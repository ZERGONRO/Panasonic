Panasonic's Project of GD!
Open the project with Flything IDE please!

//The size of UI Picture is bigger than Panasonic's HZ,So the UI Display will 
  freezed morely!

##########################################################
2021/7/20
1,Every timer's data was not to saved when you turn on other UI display.
2,If you use the array to recording the device timer data, and you initial the
array before you use it,that would be display the garbled and timer's data could'n be saved for every device.

2021/7/21
1,If you need use the pointer to pointing the variable and operate it,you must malloc the ram for the pointer so that you can operate it,and suggest you free it when you exit or don'n use it.
2,System point the signal 6 and signal 11,maybe the buffer is overflow or free the pointer twice,and it alse point the invalid pointer because the ram address had changed when you free the ram,so notice the use of pointer and ram.

2021/7/22
1,Althouh you malloc a ram for the struct which include a varible and a pointer,you want to operate the pointer,you must malloc a ram for the pointer. 

2021/7/26
1,If you want to strcpy string to another string, you alloc the string arrays better.If you want to strcmp two string, you use the std::string(string).c_string to compare.




















