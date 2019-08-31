#ifndef COMMAND_H
#define COMMAND_H

namespace util{

    class Command{
        public:

            // Const Parameter
            enum {
                ESC = 100,
                UpArrow,
                DownArrow,
                LeftArrow,
                RightArrow,
                Space,
                Null,
            };

            // Constructor
            Command();
            
            // Get Input key
            void getInput();

            // Check input key
            int getKeyType() const;

            // Reset
            void reset();

        private:
            int prefix;
            int postfix;
            int keyType;
    };

} // namespace util

#endif