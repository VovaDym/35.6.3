#include <iostream>
#include <filesystem>
#include <string>





int main()
{
    std::cout << "Enter path: ";
    std::filesystem::path path;
    std::cin >> path;
    std::cout << "Enter extension: ";
    std::string ext;
    std::cin >> ext;
    if (ext[0] != '.')
    {
        ext.insert(ext.begin(), '.');
    }
        
    auto recursiveGetFileNamesByExtension = [](std::filesystem::path file, const std::string& extension)
    {
        const int compareEqual = 0;
        if (std::filesystem::is_regular_file(file) && (file.extension().compare(extension) == compareEqual))
        {
            std::cout << file << std::endl;
        }       
    };

    for (const auto& p : std::filesystem::recursive_directory_iterator(path))
    {
        recursiveGetFileNamesByExtension(p.path(), ext);
    }
}