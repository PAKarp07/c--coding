#include <iostream>
#include <filesystem>
#include <string>


using namespace std;
namespace fs = std::filesystem;


void listFiles(const string& path){

    for(const auto& entry : fs::recursive_directory_iterator(path)){
        cout << " - " << entry.path().filename() << endl;

    }

}


int main() {

    cout << "|-|-|-|-|-|-|-|-|-| List of files in a folder |-|-|-|-|-|-|-|-|-|" << endl;

    string path = "./parent_folder";
    cout << "Files in the folder 'parent_folder':" << endl;

    listFiles(path);



    return 0;
}
