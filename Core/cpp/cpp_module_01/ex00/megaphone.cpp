#include "iostream"

int main(int argc, char **argv){
    int i;
    int j;

    i = -1;
    if(argc < 2)
        std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
        while(argc > 1 && argv && argv[++i])
        {
            j = -1;
            while(i > 0 && argv[i][++j])
                std::cout <<(char)std::toupper(argv[i][j]);
        }
        std::cout<<std::endl;
    return  0;
}