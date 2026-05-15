#include <iostream>
        if (reg == "AH") return AH;
        if (reg == "BL") return BL;
        if (reg == "BH") return BH;

        return 0;
    }
};

// =======================
// MAIN
// =======================
int main() {

    Memory memory;
    CPU cpu;

    vector<Instruction> program;

    program.push_back(Instruction(
        "MOVE",
        {"AL", "10"},
        "Move value to register",
        2
    ));

    program.push_back(Instruction(
        "MOVE",
        {"BL", "5"},
        "Move value to register",
        2
    ));

    program.push_back(Instruction(
        "ADD",
        {"AL", "BL"},
        "Add registers",
        2
    ));

    program.push_back(Instruction(
        "STORE",
        {"100"},
        "Store ACC in memory",
        1
    ));

    cout << "===== START PROGRAM =====" << endl;

    for (Instruction instr : program) {
        cpu.execute(instr, memory);
    }

    memory.printMemory();

    cout << "\n===== END PROGRAM =====" << endl;

    return 0;
}
