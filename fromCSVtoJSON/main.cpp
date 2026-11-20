#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <charconv>


using std::vector;
using std::cout;
using std::endl;
using std::string;

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);

    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::optional<int> tryParseInt(std::string_view str) {
    int value = 0;
    auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), value);

    // Check for no error and ensure the entire string was consumed
    if (ec == std::errc() && ptr == str.data() + str.size()) {
        return value;
    }
    return std::nullopt;
}

int main(){
    string csv =
R"(cuenta,nombre,carrera,correo,edad,esBecado
123,victor,sistemas,v@unitec.edu,21,true
124,joshua,sistemas,j@unitec.edu,,false)" ;

    string generatedJSON = "[\n";

    const vector<string> lines = split(csv,'\n');
    if(lines.size()>0){
        const vector<string> columns = split(lines[0], ',');
        for(int i=1; i<lines.size(); i++){ // n
            const auto values = split(lines[i], ','); // m
            generatedJSON += "{\n";
            for(int j=0; j<columns.size(); j++){ // p
                // case 1 : valor no existe
                if(values[j] == ""){
                    continue;
                }
                generatedJSON += "\t\"" + columns[j] + "\":";
                // + values[j] + "\"";
                if(values[j] == ""){
                    generatedJSON += "null";
                }
                else if(tryParseInt(values[j])){
                    generatedJSON += values[j];
                } else if(values[j] == "true" || values[j] == "false"){
                    generatedJSON += values[j];
                } else {
                    generatedJSON += "\"" +  values[j] + "\"";
                }
                if(j == values.size()-1){
                    generatedJSON += "\n";
                } else {
                    generatedJSON += ",\n";
                }
            }
            if(i == lines.size()-1){
                generatedJSON += "}\n";
            } else {
                generatedJSON += "}, \n";
            }
        }
    }

    generatedJSON += "]";

    cout << generatedJSON << endl;

    return 0;
}




