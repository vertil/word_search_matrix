#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iterator>

struct position{
  int l;
  int c;
};

bool path(position zz, std::vector<position> & pathes,std::string & word,
            const std::vector <std::vector<char>>& matrix,int & n){
                
    pathes.push_back(zz);
    
    //std::cout<<zz.l<<":"<<zz.c<<" "<<static_cast<int>(word.size())<<std::endl;
    
    if(pathes.size()==word.size()){
        return true;
    }else{
        //up
        if(zz.l-1>=0 && matrix[zz.l-1][zz.c]==word.at( static_cast<int>( pathes.size() ) ) && path({zz.l-1,zz.c},pathes,word,matrix,n)==true){
            //std::cout<<"up"<<std::endl;
            
        //righr    
        }else  if(zz.c+1<n && matrix[zz.l][zz.c+1]==word.at( static_cast<int>( pathes.size() ) ) && path({zz.l,zz.c+1},pathes,word,matrix,n)==true){
            //std::cout<<"right"<<std::endl;   
            
        //down    
        }else if(zz.l+1<n && matrix[zz.l+1][zz.c]==word.at( static_cast<int>( pathes.size() ) ) &&path({zz.l+1,zz.c},pathes,word,matrix,n)==true){
           // std::cout<<"down"<<std::endl;
            
        //left    
        }else if(zz.c-1>=0 && matrix[zz.l][zz.c-1]==word.at( static_cast<int>( pathes.size() ) ) &&path({zz.l,zz.c-1},pathes,word,matrix,n)==true){
            //std::cout<<"left"<<std::endl;
            
        }else{
            pathes.pop_back();
            return false;
        }
        
        
    }
}

int main()
{
    std::string strmtrx;
    std::string word;
    
    std::cout<<"write matrix"<<std::endl;
    std::cin>>strmtrx;
    //strmtrx="wbnhhyupomesfghj";
    std::cout<<"write word"<<std::endl;
    std::cin>>word;
    //word="home";
    
    int n=static_cast<int>( sqrt( static_cast<int>(strmtrx.size()) ) ) ;
    
    std::vector< std::vector<char> > matrix(n);
    
    std::vector<position> pathes;
    //matrix
    for(int i=0;i<n;i++){
        std::copy(strmtrx.begin()+(n*i), strmtrx.begin()+n+(n*i)  , std::back_inserter(matrix[i]) );
    }
    
    bool z=true;
    for(int i=0;i<n && z==true;i++){
        for(int j=0;j<n && z==true;j++){
            if(matrix[i][j]==word.at(0)){
                if(path({i,j},pathes,word,matrix,n)==true){
                    std::cout<<"find"<<std::endl;
                    z=false;
                    
                }
                
            }
        }
    }
    
   //show matrix
   std::cout<<"[";
    for(int i=0;i<n;i++){
        for( int j=0;j<n;j++){
            std::cout<<matrix[i][j]<<",";
        }
        if(i==n-1){
            std::cout<<"]"<<std::endl;
        }else{
            std::cout<<std::endl;
        }
        
    }
   
    for(auto i:pathes){
        std::cout<<"["<<i.l<<":"<<i.c<<"]"<<std::endl;
    }
    

    return 0;
}