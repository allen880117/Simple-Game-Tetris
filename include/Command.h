#ifndef COMMAND_H
#define COMMAND_H

namespace util{

    enum {
        ESC = 100,
        UpArrow,
        DownArrow,
        LeftArrow,
        RightArrow,
        Space,
        Null,
    };

    class Command{
        public:
            // Constructor
            Command();
            
            // Get Input key
            void getInput();

            // Check input key
            int getKeyType();

            // Reset
            void reset();

        private:
            int prefix;
            int postfix;
            int keyType;
    };

} // namespace util

#endif