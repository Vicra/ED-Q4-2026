#include <string>
#include <iostream>
#include <sstream>


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

int main(){
    string csv =
R"(cuenta,nombre,carrera,correo,edad,esBecado
123,victor,sistemas,v@unitec.edu,21,true
124,joshua,sistemas,j@unitec.edu,,false)" ;

    string generatedJSON = "[\n";

    const auto lines = split(csv,'\n');
    const auto columns = split(lines[0], ',');
    for(int i=1; i<lines.size(); i++){
        const auto values = split(lines[i], ',');
        generatedJSON += "{\n";
        for(int j=0; j<values.size(); j++){
            generatedJSON += "\t\"" + columns[j] + "\""
                             + ":" + "\"" + values[j] + "\"";
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
    generatedJSON += "]";

    cout << generatedJSON << endl;

    return 0;
}




