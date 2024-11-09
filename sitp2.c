#include <stdio.h>

void calculatePension(int age, int yservice, float avsalary, char gender) {
  
    if ((gender == 'M' && age < 60) || (gender == 'F' && age < 55)) {
        printf("Not eligible for retirement.\n");
        return;
    }

    if (yservice < 5) {
        printf("Error: Minimum years of service should be at least 5.\n");
        return;
    }

    float pension;
    if (yservice * 2.5 > 80) {
        pension = 80;
    } else {
        pension = yservice * 2.5;
    }

    float pbenefit = (pension / 100) * avsalary;

    float ss = pbenefit * 0.02;

    float irgTax;
    if (pbenefit > 50000) {
        irgTax = pbenefit * 0.2;
    } else if (pbenefit > 30000) {
        irgTax = pbenefit * 0.1;
    } else {
        irgTax = 0;
    }

    pension = pbenefit - ss - irgTax;

    if (pension < 15000) pension = 15000; 
    if (pension > 200000) pension = 200000; 

    printf("Pension: %.0f DA\n", pension); 
}

int main() {
    int age, yservice;
    float avsalary;
    char gender;

    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter years of service: ");
    scanf("%d", &yservice);
    printf("Enter average salary (last 5 years): ");
    scanf("%f", &avsalary);
    printf("Enter gender (M/F): ");
    scanf(" %c", &gender);  

    calculatePension(age, yservice, avsalary, gender);

    return 0;
}