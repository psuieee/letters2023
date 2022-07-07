#include <vector>
#include <string>
#include <map>

#include "CommandSender.h"
#include "Pattern.h"
#include "Source.h"

struct SourceData {
    Source source;
    void *sourceData;
};

struct PatternData {
    Pattern pattern;
    std::vector<std::string> subscriptions; // names of sources
};

class LetterCore {
public:
    LetterCore(const char *ip, int port);

    void step();

    void addSource(Source source, std::string sourceName);
    void addPattern(Pattern pattern, std::vector<std::string> subscriptions);


private:

    std::map<std::string, SourceData> sources; // map from source name to sourcedata
    std::vector<PatternData>    patterns;

    CommandSender commandSender;

};