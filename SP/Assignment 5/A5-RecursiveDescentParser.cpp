/* Systems Programming Lab
 * Yatish Kelkar TE IT 8001
 * Assignment 5 : Recursive Descent Parser
 * 22/05/21
*/


#include<stdio.h>
#include<ctype.h>
#include<string.h>

 
class RecursiveDescentParser
{
    public:  
      char expression[10];
      int count, flag;

    void E();
    void T();
    void Tprime();
    void check();
    void Eprime(); 

    RecursiveDescentParser () {
        count = 0;
        flag = 0;
        printf("\nEnter an Algebraic Expression:\t");
        scanf("%s", expression);
        E();
        if((strlen(expression) == count) && (flag == 0))
        {
                printf("\nThe Expression %s is Valid\n", expression);
        }
        else 
        {
                printf("\nThe Expression %s is Invalid\n", expression);
        }
    }    
};

                    
void RecursiveDescentParser :: E()
{
      T();
      Eprime();
}

void RecursiveDescentParser :: T()
{
      check();
      Tprime();
}
 
void RecursiveDescentParser :: Tprime()
{
      if(expression[count] == '*')
      {
            count++;
            check();
            Tprime();
      }
}
 
void RecursiveDescentParser :: check()
{
      if(isalnum(expression[count]))
      {
            count++;
      }
      else if(expression[count] == '(')
      {
            count++;
            E();
            if(expression[count] == ')')
            {
                  count++;
            }
            else
            {
                  flag = 1; 
            }
      }         
      else
      {
            flag = 1;
      }
}

void RecursiveDescentParser :: Eprime()
{
      if(expression[count] == '+')
      {
            count++;
            T();
            Eprime();
      }
}
 
int main()
{
    RecursiveDescentParser object;
}