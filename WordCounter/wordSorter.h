#include <vector>

namespace PRAC{

    int tryMe();

    class printer{
        public:
            void practice();
        
        private:
            
    };
}

namespace DEW{

    class sorter{

        public:
            sorter();
            sorter(std::string newFile);
            std::vector<std::string> sort();
            bool getHasDocument();


        
        private:
            bool hasDocument;
    };
}