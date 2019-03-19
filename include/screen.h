#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>
#include <map>

using namespace std;
//�s��ƪ����c
struct DataStore{
	string line=" ";
	string mark=" ";
	string opcode=" ";
	string label=" ";
	string objectCode=" ";
	string loc=" ";
	char n='1',i='1',x='0',b='0',p='1',e='0';
	char two='0';
};
//�sopcode�����c
struct op{
	string opcode=" ";
	string format=" ";
	string num=" ";
	string binarycode=" ";
};

class screen
{
    public:


    protected:
        //����ܥ\��
        void PrintOpCode(vector<struct op>);
        void PrintVector(vector<struct DataStore>);
        void SetColor(int);
        void PrintSymtab(map<string,string>);
        void PrintOptab(map<string,string>);

    private:
};

#endif // SCREEN_H
