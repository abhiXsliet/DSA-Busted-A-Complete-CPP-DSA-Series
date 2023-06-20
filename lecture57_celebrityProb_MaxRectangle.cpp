//Q1. Did celebrity problem on GFG by using some step as following
    //step 1 -> we created a stack and pushed all the elements into the stack 
    //step 2 -> while(stack.size() > 1) then we pop out two elements from the stack and check wheather they knows each other or not; 
                //create a knows function as if(M[a][b] == 1) then true else false;
    //step 3 -> we'll get a potential candidate outside the for loop
    //step 4 -> check the respective rows and col elements as 0 and 1
                //make variables oneCount and zeroCount = 0, check the row and col elements inside the for loop as 0 and 1 respectively. 
                //At the same oneCount++ & zeroCount++ inside the for loop 
                //if (zeroCount != n) and (oneCount != n-1) then return -1;
    
    //step 5 -> if(row and col element of potential celebrity is true then return potential celebrity)




//Q2. Maximum Rectangle on GFG
//(This Question will clear the concept of Histogram Rectangle area/as well as all the nextElement and prevElement finding concept)
//step involved;
//step 1 -> finding the area of first row 
        // int area = largestRectangleArea(M[0], m);
            //largestRectangle area --> i. makes vector next and prev of n size . next = nextSmallerElement(int* arr, int n) && prev = prevSmallerElement(int* arr, int n)
                //nextsmallerElement -> i. stack bnao, -1 dalo aur loop chlao-> aur curr bnao then while( s.top()!= -1 && s.top() >= curr )then pop karo otherwise ans[i] = s.top() and push kardo then return krdo ans ko
//step 2 -> updating row's by adding prev row's element only if the row's(2, 3, 4...) elements are non-zero

//step 3 -> calculate & return max area of largestRectangelArea(M[i], m)