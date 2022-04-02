#include "ScriptManager.h"

ScriptManager::ScriptManager()
{
    scripts = std::vector<Script*>();
}

/// <summary>
/// Creates a Script
/// </summary>
/// <param name="fileName">The name of the file (NO FILE EXTENSION)</param>
/// <returns>The new Script object</returns>
Script* ScriptManager::createScript(std::string _fileName)
{
    std::string cpp = _fileName + ".cpp";
    std::string h = _fileName + ".h";

    ofstream outFile;
    outFile.open(cpp);

    if (outFile.is_open()) {
        outFile << 
        "#include \"" + _fileName + ".h\"\n"
        "\n"
        "" + _fileName + "::" + _fileName + "() : Script::Script(\"" + _fileName + "\")\n"
        "{\n"
        "}\n"
        "\n"
        "void " + _fileName + "::" + "start()\n"
        "{\n"
        "\tDebug::print(\"Hello " + _fileName + "!\", true);\n"
        "}\n"
        "\n"
        "void " + _fileName + "::" + "update()\n"
        "{\n"
        "}\n"
        "\n"
        "void " + _fileName + "::" + "fixedUpdate()\n"
        "{\n"
        "}";
    }
    else {
        std::cout << "The file could not be created! Please try again." << std::endl;
    }

    outFile.close();

    outFile.open(h);

    if (outFile.is_open()) {
        outFile << 
        "#pragma once\n"
        "#include \"Script.h\"\n"
        "\n"
        "class " + _fileName + ":\n"
        "\tpublic Script\n"
        "{\n"
        "public:\n"
        "\t" + _fileName + "();\n"
        "\t\n"
        "\t// You only have to implement the functions that you need\n"
        "\t// Unneeded ones can be removed with no problems\n"
        "\tvoid start() override;\n"
        "\tvoid update() override;\n"
        "\tvoid fixedUpdate() override;\n"
        "};";
    }
    else {
        std::cout << "The file could not be created! Please try again." << std::endl;
    }

    outFile.close();

    Script* script = new Script(_fileName);

    scripts.push_back(script);

    return script;
}