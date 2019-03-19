#include "InputFile.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <windows.h>


InputFile::InputFile()
{
    //ctor
}

void InputFile::inputTxtFile(){


	//�ŧi�ɮ�'file
	fstream file,fileLine,opcode,opcode1;

	//�}�ҤT���ɮ�
	file.open("Figure2.15.txt",ios::in);
	fileLine.open("Figure2.16.txt",ios::out);
	opcode.open("op_code.txt",ios::in);

	string Line,num;
    int numInt;

    //OPCODE�s�X
    while(getline(opcode,Line)){
        istringstream delim(Line);

        string op1,format,code;
        op re;

        delim>>op1>>format>>code;
        re.opcode=op1;
        re.format=format;
        re.num = code;
        re.binarycode = HexToBinary(code);
		op_code.push_back(re);

	}

	int i=0;
	//���C�@��s���s�^"Figure2.16.txt"
	while(getline(file,Line)){
		fileLine<<IntToString(i)<<"\t"<<Line<<endl;
		i++;
	}

	D_register.resize(i);

	fileLine.close();
    file.close();
    opcode.close();

	fileLine.open("Figure2.16.txt",ios::in);
	opcode1.open("op_code2.txt",ios::out);

  //�q�ɮפ����r��
	while(getline(fileLine,Line)){
        string first,second,third;
		istringstream delim(Line);
		//��J�s��
		delim>>num;
		numInt = StringToInt(num);
        D_register[numInt].line=num;

		delim>>first;
        if(first=="."||first==""){
            second=" ";
            D_register[numInt]=grabLine(num,first,second);
            continue;
        }
        //�P�_�Ĥ@�ӼƦr�O���OOPCODE
        if(judgeop(first)){
            delim>>second;

            D_register[numInt]=grabLine(num,first,second);
            judgeformat(first,D_register,numInt);

        }else{
            delim>>second;
            //�P�_�ĤG�ӼƦr�O���OOPCODE
            if(judgeop(second)){
                delim>>third;

                D_register[numInt]=grabLine(num,first,second,third);
                judgeformat(second,D_register,numInt);
            }else{
                //�ĤG�Ʀr�����OOPCODE�A�@�w��
                 cout<<"error message"<<endl;
            }
        }

	}

	string ss;

    //OP_CODE�t�۽s���g�J�ɮ�
	for(unsigned int i = 0; i<op_code.size();i++){
        opcode1<<left<<setw(10)<<op_code[i].opcode<<setw(10)<<op_code[i].format
             <<setw(10)<<op_code[i].num<<setw(10)<<op_code[i].binarycode<<endl;

    }




    opcode1.close();
	fileLine.close();



}
//�N�S��mark�����n����Ʃ�J��Ƶ��c��
struct DataStore InputFile::grabLine(string num,string first ,string second){
    struct DataStore re;
    re.line = num;
    re.mark =" ";
    re.opcode = first;
    re.label= second;

    return re;

}
//�h����ơA�N��mark�����n����Ʃ�J��Ƶ��c��
struct DataStore InputFile::grabLine(string num,string first ,string second,string third){
    struct DataStore re;
    re.line = num;
    re.mark = first;
    re.opcode = second;
    re.label = third;


    return re;

}
//�P�_��ƬO���Oformat4�A���O��
void InputFile::judgeformat(string str,vector<struct DataStore>&use,int num){

    string real;

    if(str[0]=='+'){
        use[num].b='0';
        use[num].p='0';
        use[num].e='1';
    }


}
//�P�_�O���OOPCODE
bool InputFile::judgeop(string str){

    string real;
    if(str[0]=='+'){

        str = str.substr(1);
    }
    for(unsigned int i=0;i<op_code.size();i++){
        if(str==op_code[i].opcode){
            return true;
        }


    }

    return false;

}
//INT��STRING
string InputFile::IntToString(int number){
	stringstream ss;
	ss<<number;

	return ss.str();
}
//STRING��INT
int InputFile::StringToInt(string s){
	stringstream ss;
	int number;
	ss<<s;
	ss>>number;

	return number;
}
//�Q���i����G�i��
string InputFile::HexToBinary(string ss){

    string print="";

    for(unsigned int i = 0 ; i < ss.size();i++){
        switch(ss[i]){
            case '0' :{
                print+="0000";
                break;
            }
            case '1' :{
                print+="0001";
                break;
            }
            case '2' :{
                print+="0010";
                break;
            }
            case '3' :{
                print+="0011";
                break;
            }
            case '4' :{
                print+="0100";
                break;
            }
            case '5' :{
                print+="0101";
                break;
            }
            case '6' :{
                print+="0110";
                break;
            }
            case '7' :{
                print+="0111";
                break;
            }
            case '8' :{
                print+="1000";
                break;
            }
            case '9' :{
                print+="1001";
                break;
            }
            case 'A' :{
                print+="1010";
                break;
            }
            case 'B' :{
                print+="1011";
                break;
            }
            case 'C' :{
                print+="1100";
                break;
            }
            case 'D' :{
                print+="1101";
                break;
            }
            case 'E' :{
                print+="1110";
                break;
            }
            case 'F' :{
                print+="1111";
                break;
            }
        }
    }
    return print;

}
