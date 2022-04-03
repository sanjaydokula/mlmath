#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<numeric>

using namespace std;

template<typename Tx, typename Ty>
class Pair
{
public:
    /* data */
    pair<Tx,Ty> p;
public:
    Pair();
    Pair(/* args */Tx,Ty);
    Pair<Tx,Ty> operator+(const Pair<Tx,Ty>&) const; // addition overload
    Pair<Tx,Ty> operator-(Pair<Tx,Ty>); // subtraction overload
    Pair<Tx,Ty> operator*(Tx); // multiplication overload

};

template<typename Tx, typename Ty>
Pair<Tx,Ty>::Pair(){
    this->p = make_pair(0,0);
}

template<typename Tx,typename Ty>
Pair<Tx,Ty>::Pair(/* args */Tx x, Ty y)
{
    this->p = make_pair(x,y);
}


template<typename Tx,typename Ty>
Pair<Tx,Ty> Pair<Tx,Ty>::operator+ (const Pair<Tx,Ty> &p) const{
    Pair<Tx,Ty> result;
    result.p.first = this->p.first + p.p.first;
    result.p.second = this->p.second + p.p.second;
    return result;
}

template<typename Tx,typename Ty>
Pair<Tx,Ty> Pair<Tx,Ty>::operator- (Pair<Tx,Ty> p){
    Pair<Tx,Ty> result;
    result.p.first = this->p.first - p.p.first;
    result.p.second = this->p.second - p.p.second;
    return result;

}

template<typename Tx,typename Ty>
Pair<Tx,Ty> Pair<Tx,Ty>::operator* (Tx m){
    Pair<Tx,Ty> result;
    result.p.first = this->p.first*m;
    result.p.second = this->p.second*m;
    return result;

}


int gcd(int a,int b){
    while (a != b ){
        if (a > b){

            a = a - b;
        }
        else{

            b = b - a;
        }
    return a ;
    }
}
int main(void){

    Pair<int,int>  vec(3,2);
    Pair<int,int> vec2(-1,2);

    Pair<int,int> vec3 = vec*2;
    cout<<vec3.p.first<<" "<<vec3.p.second<<endl;


    double dist;

    // dist = hypot(vec3.p.first-0,vec3.p.second-0);
    int bin = gcd(vec3.p.first,vec3.p.second);
    // cout<<bin;

    int x_bin = vec3.p.first/bin;
    int y_bin = vec3.p.second/bin;

    // cout<<(int)dist<<endl;
    vector<pair<int,int> > vect(bin,std::make_pair(0,0));
    int t_x = 0;
    int t_y = 0;
    for (int i = 0;i<=bin;i++) {

        vect[i] = make_pair(t_x,t_y);
        t_x+=x_bin;
        t_y+=y_bin;
    }

    for (int i = 0;i<=bin;i++) {
        cout<<vect[i].first<<" "<<vect[i].second<<endl;
    }

    // string GnuCommands = {"set title \"vectors\"", "plot 'data.tmp'"};


    char *GnuCommands [] ={"set title \"Demo\"","plot 'data.tmp' with vectors arrowstyle 3"};
    cout<<GnuCommands[0];
    FILE *fp = nullptr;
    FILE *gnupipe = nullptr;

    fp = fopen("data.tmp","w");
    gnupipe = _popen("gnuplot -persistent","w");
    


    // for (int i = 0;i<=bin;i++) {
        fprintf(fp,"%d %d %d %d\n",0,0,3,0);
        fprintf(fp,"%d %d %d %d\n",0,0,2,1);
        fprintf(fp,"%d %d %d %d\n",0,0,1,-1);
    // }

    for (int i =0;i<2;i++){
        fprintf(gnupipe,"%s\n",GnuCommands[i]);
    }

}

