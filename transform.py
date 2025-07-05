#!/usr/bin/env python3
import sys
import json

def main():
    input_data = json.load(sys.stdin)
    output_list = []

    for compiler, compiler_tests in input_data.items():
        for compiler_test in compiler_tests:
            for version in compiler_test["versions"]:
                for versions_test in compiler_test["tests"]:
                    for cxxversion in versions_test["cxxversions"]:
                        for cxxversion_test in versions_test["tests"]:
                            for stdlib in cxxversion_test["stdlibs"]:
                                for stdlib_test in cxxversion_test["tests"]:
                                    test = {
                                        "compiler": compiler,
                                        "version": version,
                                        "cxxversion": cxxversion,
                                        "stdlib": stdlib,
                                        "test": stdlib_test
                                    }
                                    output_list.append(test)
    json.dump(output_list, sys.stdout, indent=2)

if __name__ == "__main__":
    main()
