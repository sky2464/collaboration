// Difrrent sight by using array and pointer maybe it helps you to get the idea

#include<string>
#include<cctype>
#include<fstream>
#include<iostream>

using namespace std;

//If we simplify your problem statement it is searching a word from a set of words.
//1st we will split the string into words then we will compare with the given string

bool findWord(string str, string word)
{
/* char *p = strchr(str, ' ');   
//cout<<*(p-1)<<endl;
char *words[100]; // assuming not more than 100 words in that string
//cout<<str<<endl;
words[0]=str;
int i=1,index;
char* temp;
while( p!= NULL )
{
//cout<<*(p-1)<<endl;
temp=p;
while(p!= NULL && !isalpha(*(p+1))) // skip the extra spaces and tabs
p++;
index = (int)(p - str);
cout<<index<<endl;
//cout<<*(p+1)<<endl;
words[i]=p+1; //soring the word into the word list
str[index]='\0';
i++;
p = strchr(p+1, ' ');

}
int len =i;
for(i=0;i<len;i++)
{
cout<<words[i];
}
  
for(i=0;i<len;i++)
{
if(strcmp(words[i],word))
return true;
}
return false;*/

const char *string = str.c_str();
int start_index=0;
char *p = strchr(string, ' ');
int end_index = (int)(p - string);

while( p!= NULL)
{
cout << start_index <<" " << end_index<<endl; // splitting the sentence with spce delimiter
cout<<str.substr(start_index,end_index-start_index)<<endl;
if(word.compare(str.substr(start_index,end_index-start_index))==0) // checking if the substring is matching with the mentioned word
return true;
while(p!= NULL && !isalpha(*(p+1))) // skip the extra spaces and tabs
p++;
start_index = (int)(p - string)+1;
p = strchr(p+1, ' ');
end_index = (int)(p - string);
}
if(word.compare(str.substr(start_index,str.length()-start_index))==0) // checking with the last word
return true;
return false;
  
}

int main()
{
char* string = "I am CSE SME";
char* word = "SME";
  
if(findWord(string,word))
cout<<"Word is present"<<endl;
else
cout<<"Word is not present"<<endl;
getchar();
return 0;
}
