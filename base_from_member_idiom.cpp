#include <iostream>

struct superBase {
    int value;
    superBase(int v) : value(v) {
    }
};

struct Primary {
    superBase sb;
    Primary(superBase s) : sb(s) {
    }
};

struct Secondary : public superBase {
    Secondary(int a) : superBase(a) {
    }
};

struct Helper {
   protected:
    Secondary sec;

   public:
    Helper(int v) : sec(v) {
    }
};

struct Child : public Helper, public Primary {
   public:
    Child(int a) : Helper(a), Primary(sec) {
        std::cout << "I Got " << a << std::endl;
    }
};

int main() {
    Child ch(3);
    std::cout << "Fetched value: " << ch.sb.value;

    std::cout << std::endl;
    return 0;
}
