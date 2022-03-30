#include <iostream>
#include "Notebook.hpp"
#include <unordered_map>
#include "Direction.hpp"
using namespace ariel;
using ariel::Direction;
#include <stdexcept>
#include <string>


using namespace std;
namespace ariel{
void Notebook::write(int page, int row, int col, Direction direction, std::string a){
  if(a=="\n"){
      throw invalid_argument("bad input");
  }
  if(page>=0&&row>=0&&col>=0&&col<MAX_ROW){
  if(page<min_page){
      min_page=page;
  }  
  if(row<min_row){
      min_row=row;
  }  
  if(col<min_col){
      min_col=col;
  }  
  newLine(page, row);
    if (direction==ariel::Direction::Horizontal){
        if(col+(int)a.size()>MAX_ROW){
            throw invalid_argument("out of boundaries");
        }
                for(unsigned int i=0;i<a.size();i++){
                    if(a[i]=='~'){
                        throw invalid_argument("bad input");
                    }
                    if(book[page][row][col]=='_'){
                        book[page][row][col++]=a[i];
                        
                    }  
                    else{throw invalid_argument("already written");}  
                  }
                }
    else {
                   
                    for(unsigned int i=0;i<a.size();i++){
                        if(a[i]=='~'){
                            throw invalid_argument("bad input");
                    }
                        if(book[page][row][col]=='_'){
                            book[page][row++][col]=a[i];
                            newLine(page, row);
                            
                    }  
                        else{throw invalid_argument("already written");}
                }

}
if(page>max_page){
    max_page=page;
}
if(row>max_row){
    max_row=row;
}
if(col>max_col){
    max_col=col;
}
  }else{ 
     throw invalid_argument("out of boundaries");}

}

string Notebook::read(int page, int row, int col, Direction direction, int numOfChars){
    if(page<0||row<0||col<0||col>=MAX_ROW||numOfChars<=0){
        throw invalid_argument("out of boundaries");
    }
    string ans;
    newLine(page, row);
    if (direction==ariel::Direction::Horizontal){
        if(col+numOfChars>MAX_ROW){
             throw invalid_argument("out of boundaries");
        }
             for(int i=0; i<numOfChars; i++){
                ans+=book[page][row][col+i];}
     }
    else
        {
         for(int i=0; i<numOfChars; i++){
            newLine(page, row+i);
            ans+=book[page][row+i][col];}

         }
    
    return ans;
}

void Notebook::erase (int page, int row, int col, Direction direction, int numOfChars){
    if(page<0||row<0||col<0||col>=MAX_ROW||numOfChars<=0){
        throw invalid_argument("out of boundaries");
    }
    if (direction==ariel::Direction::Horizontal){
         if(col+numOfChars>MAX_ROW){
             throw invalid_argument("out of boundaries");
        }
        for(int i=0;i<numOfChars;i++){
            book[page][row][col++]='~';  
                  }
                }
    else{
        for(int i=0;i<numOfChars;i++){
            book[page][row++][col]='~';
                }

}  
}

void Notebook::show(int page){
    if(page<0){
        throw invalid_argument("out of boundaries");
    }
    for(int k=min_page; k<max_page;k++){
        for(int i=min_row;i<max_row;i++){
            for(int j=min_col;j<max_col;j++){
                if(book.find(i)!=book.end()){
                    if(book[i].find(j)!=book[i].end()){
                        cout<<book[page][i][j]<<endl;}
           }
                else{
                    cout<<'_'<<endl;}
        }
                        cout<<'\n'<<endl;
}
    }
}

void Notebook::newLine(int page, int row){
    if(book[page][row][0]=='\0'){
    for(int i=0; i<MAX_ROW; i++){
        book[page][row][i]='_';
    }
    }
}
}
