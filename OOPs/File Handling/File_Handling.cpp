// Example: You are in India, and your friend lives in the US, who has a file with the data '2, 3, 1, 0, 4'
// Your friend sent you the file and we'll write a sorting algorithm
// We'll copy the data and paste here as an input and we get the result as output
// We'll paste the output in the file and send it to friend.
// This is not the most efficient way to sort the data.
// We can just directly read and write the data to the file, instead of copy pasting.

// Normally, the code executes in RAM, and we want to store the data permanently in secondary memory (SM)
// Data in the RAM is temporary, but data in SM is permanent, until the time we delete it.
// How do we store it?
// One way is to create a file in secondary memory, and open in RAM, update the data and send back to SM.
// What we can do is write data in RAM and then read in Secondary Memory

// We have ofstream and ifstream classes
// ofstream to write data to the file, We can create the object of this to read and wite data on it and store in SM
// ifstream to read data from the file. We can create the object of this from where we can open and read file data
// The file is a real world object/entity, we use these classes to read and write data.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    // Open and Write in File
    ofstream fout; // fout is an object
    // open is a member function through which we perform an action
    fout.open("C:\\Users\\Cherry\\Downloads\\Projects\\Notes\\OOPs\\File Handling\\zoom.txt");
    // Using full path to ensure file creation
    // If the file is not present, it will create the file and open it
    // We can also use just the file name if we have write permissions in current directory
    if (!fout)
    {
        cout << "File creation failed!" << endl;
        return 1;
    }

    fout << "Hello World"; // This is used to write data to the file

    // Get array input from user
    vector<int> arr(5);
    cout << "Enter the Input: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    // Write original array data to file
    fout << "\nOriginal data: \n";
    for (int i = 0; i < 5; i++)
    {
        fout << arr[i] << " ";
    }

    // Sort array and write sorted data to file
    fout << "\nSorted data: \n";
    sort(arr.begin(), arr.end()); // Sort the array in ascending order
    for (int i = 0; i < 5; i++)
    {
        fout << arr[i] << " ";
    }

    // Write additional sample text to file
    fout << "\nHello Cherry\n";
    fout << "Hello World\n";
    fout << "Hello India\n";

    fout.close(); // Close the file

    // Open and Read from File
    ifstream fin; // Create an object
    fin.open("C:\\Users\\Cherry\\Downloads\\Projects\\Notes\\OOPs\\File Handling\\zoom.txt");

    // Check if file opened successfully for reading
    if (!fin)
    {
        cout << "File opening failed!" << endl;
        return 1;
    }

    cout << "\nReading from file:\n";
    string line; // Variable to store each line from file
    // getline() reads entire line including spaces, unlike >> operator
    while (getline(fin, line))
    {
        cout << line << endl; // Display each line
    }

    fin.close(); // Always close file after operations

    return 0;
}