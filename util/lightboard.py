'''
Lightboard

An RGB LED matrix simulator developed to ease development for LED matrices 
powered by hobbyist microcontroller platforms. Individual LEDs are addressed and
controlled over TCP, using commands which take the following form:

| Name      | Bytes | Datatype  | Description                                  |
|-----------|-------|-----------|----------------------------------------------|
| Column    | 4     | uint32_t  | Column # of target LED (leftmost column is 0,|
|           |       |           | rightmost column is width-1)                 |
| Row       | 4     | uint32_t  | Row # of target LED (bottom row is 0, topmost|
|           |       |           | row is height-1)                             |
| Red       | 1     | uint8_t   | Red component of LED color (0-255)           |
| Green     | 1     | uint8_t   | Green component of LED color (0-255)         |
| Blue      | 1     | uint8_t   | Blue component of LED color (0-255)          |
|           |       |           |                                              |

Multiple of these LED commands can come in one message; multiple of these LED 
color assignments can be put in the same buffer and be parsed by this simulator.
TCP server information, matrix width/height, and LED representation size is
user-configurable. See the help page for more information.

Will McGloughlin 2022
Penn State IEEE 2022

'''


'''
Copyright 2022 Will McGloughlin

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
'''

from concurrent.futures import thread
from select import select
from time import sleep
from tkinter import X
import PySimpleGUI as pg
import socket
import argparse
import threading

parser = argparse.ArgumentParser(
    description='Simulate an MxN RGB LED matrix, addressable over TCP'
)

parser.add_argument('-x', '--width', metavar='w', type=int, default=32,
                help='Width of matrix in LEDs, default 32')
parser.add_argument('-y', '--height', metavar='h', type=int, default=32,
                help='Height of matrix in LEDs, default 32')
parser.add_argument('-s', '--ledsize', metavar='s', type=int, default=10,
                help='Sidelength (in pixels) of LEDs in GUI, default 10')
parser.add_argument('-i', '--ip', metavar='i', type=str, default='',
                help='IP for control server, default accepts all connections')
parser.add_argument('-p', '--port', metavar='p', type=int, default=10000,
                help='Port for control server, default 10000')

args = parser.parse_args()

# params
width = args.width
height = args.height
ledSidelength = args.ledsize
ip = args.ip
port = args.port

canvasSize = (width*ledSidelength, height*ledSidelength)

# init matrixstate
matrixState = []

# populate matrixState
for _ in range(height):
    newRow = []
    for _ in range(width):
        newRow.append('#000000')
    matrixState.append(newRow)

lightboard = pg.Graph(
    canvas_size=canvasSize, 
    graph_bottom_left=(0,0), 
    graph_top_right=canvasSize
)

# setup the gui layout
layout = [[lightboard]]

# make the window
window = pg.Window('Lightboard', layout=layout)
window.finalize()

# setup server
print('[TCP] Starting server...')
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind((ip, port))
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
sock.listen(1)
print('[TCP] Done')

def tcpUpdateCheck():
    readable, writable, errored = select([sock], [], [], 0)

    for sck in readable:
        if sck is sock:
            # accept connection
            conn, clientAddr = sock.accept()

            print('[TCP] Accepted new connection')

            '''
                led updates will come in this format:

                x coord     : 4 bytes, uint32_t
                y coord     : 4 bytes, uint32_t
                red val     : 1 byte, uint8_t
                green val   : 1 byte, uint8_t
                blue val    : 1 byte, uint8_t

                11 bytes total
            '''
            while True:
                data = conn.recv(11) # recieve one update

                if data:
                    # pull out data
                    x = int.from_bytes(data[0:4],   byteorder='little')
                    y = int.from_bytes(data[4:8],   byteorder='little')
                    r = int.from_bytes(data[8:9],   byteorder='little')
                    g = int.from_bytes(data[9:10],  byteorder='little')
                    b = int.from_bytes(data[10:11], byteorder='little')

                    hexColor = '#%02x%02x%02x' % (r, g, b)

                    if ((x >= width) or (y >= height)):
                        print('[TCP][WARN] Update command recieved which addressed an invalid coordinate. Ignoring that update...')
                    else:
                        print(f'[TCP][UPDATE] ({x},{y})>>{hexColor}')

                        # update the matrix state
                        matrixState[x][y] = hexColor
                else:
                    break
            
            conn.close()

# main loop
while True:
    
    # erase the lightboard
    lightboard.erase()

    # draw leds to lightboard
    for rowIdx in range(height):
        for colIdx in range(width):
            lightboard.draw_rectangle(
                (colIdx * 10, rowIdx * 10),
                ((colIdx+1) * 10, (rowIdx+1) * 10),
                fill_color=matrixState[rowIdx][colIdx]
            )
    
    lightboard.update()
    window.refresh()
    event, _ = window.read(timeout=0) 

    if event == pg.WIN_CLOSED:
        print('[MAIN] Exiting...')
        exit()

    tcpUpdateCheck()

    sleep(0.001)