/*****
      kadai1.c
*****/

#include <stdio.h>

typedef struct Person{
    
    char name[32];  //名前
    double height;  //身長
    double weight;  //体重
    
} Person;

double bmicheck(Person x){
    
    double mheight, bmi;
    
    mheight=x.height/100;
    bmi=x.weight/(mheight*mheight);
    
    return bmi;
    
}

int main(){

    double bmi;

    Person bob={"bob", 172.0, 65.0};

    bmi=bmicheck(bob);
    
    printf("%10s %5.1f %5.1f %5.1f\n", bob.name, bob.height, bob.weight, bmi);
    
    return 0;
}
