/*
 * Asignment 4 -- Arrays (part 2)
 * Author: Hesham Salama -- heshamsalama.com | hes8519@thi.de
 */

 #include <iostream>
 #include <string>
 #include <unordered_map>
 #include <functional>
 #include <iterator>
 
#define SIZE 10

 void prtArr(int* a, int len)
 {
     std::cout << "[ ";
     for ( int p = 0; p < len; p++)
     {
         std::cout << a[p] << " ";
     }
     std::cout << "]";
 }
 
 void task1(int* input)
 {
     int output[SIZE];
     int in_len = SIZE;
     int out_len = 0;
     
     std::cout << "input --> output" << std::endl;
     prtArr(input, in_len);
     std::cout << " --> ";
     prtArr(output, out_len);
     std::cout << std::endl;
     
     while(in_len > 0)
     {
         int smallest_index = 0;
         for ( int i = 0; i < in_len; i++)
         {
             if ( input[i] < input[smallest_index] )
             {
                 smallest_index = i;
             }
         }
         int smallest_number = input[smallest_index];
         
         for ( int k = smallest_index; k < in_len; k++)
         {
             input[k] = input[k + 1];
         }
         in_len--;
         
         for ( int j = out_len; j >= 0; j--)
         {
             output[j] = output[j - 1];
         }
         output[0] = smallest_number;
         
         out_len++;
         
         // Print the new input and output array contents
         prtArr(input, in_len);
         std::cout << " --> ";
         prtArr(output, out_len);
         std::cout << std::endl;
     } // end while
 }
 
 void task2(int* input)
 {
     int end = SIZE;
     
     prtArr(input, SIZE);
     std::cout << std::endl;
     while(end > 1)
     {
         int smallest_index = 0;
         for (int i = 0; i < end; i++)
         {
             if (input[i] < input[smallest_index])
             {
                 smallest_index = i;
             }
         }
         int smallest_number = input[smallest_index];
         
         for (int j = smallest_index; j < end; j++)
         {
             input[j] = input[j + 1];
         }
         end--;
         input[end] = smallest_number;
         
         // Print the new input and output array contents
         prtArr(input, SIZE);
         std::cout << std::endl;
     }
 }
 
 void runTask(std::unordered_map<int, std::function<void(int*)>>::iterator kv)
 {
     int test_inputs[5][SIZE] = {
         { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
         { 10, -7, 16, -3, -4, -1, 17, 99, -9, 80 },
         { 1, 55, -80, 4, 7, 6, 7, -13, 9, 0 },
         { -116, 95, 70, 238, 500, 640, -79, -80, -99, 101 },
         { -111, -122, -133, -144, -155, -166, -177, -188, -199, -1000 }
     };
     
     for (int i = 0; i < 5; i++)
     {
         // it->second(test_inputs[i]); // (*it).second() also === std::pair<const Key, T>& keyvalpair = *it; keyvalpair.second();
         kv->second(test_inputs[i]);
         std::cout << std::endl << "==============================" << std::endl;
     }
 }
 
 int main()
 {
     int task_number = 1;
     
     std::cout << "Please select task number: [1] for task1, [2] for task2." << std::endl;
     std::cin >> task_number;
     std::cout << std::endl;
     
     std::unordered_map<int, std::function<void(int*)>> tasks;
     
     tasks[1] = &task1;
     tasks[2] = &task2;
     
     std::unordered_map<int, std::function<void(int*)>>::iterator it = tasks.find(task_number);
     if (it == tasks.end())
     {
         std::cout << "Wrong task id selected!" << std::endl;
         return 0;
     }
     
     runTask(it);
 
     return 0;
 } // end main
