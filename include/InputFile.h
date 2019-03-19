#ifndef INPUTFILE_H
#define INPUTFILE_H

#include <string>
#include <vector>
#include "screen.h"

using namespace std;

//�~��SCREEN
class InputFile : public screen
{
    public:

    InputFile();
    void inputTxtFile();

    protected:
        string IntToString(int);
        int StringToInt(string);
        string HexToBinary(string ss);
        vector<struct op> op_code;
        //�ŧi�@��struct vector�ǳƦs���ɮ׸��
        vector<struct DataStore>D_register;
        bool judgeop(string str);
    private:

        struct DataStore grabLine(string,string ,string);
        struct DataStore grabLine(string,string , string,string);
        void judgeformat(string str,vector<struct DataStore>&,int);


};

#endif // INPUTFILE_H
