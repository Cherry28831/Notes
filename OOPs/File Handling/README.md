# File Handling in C++

## Overview
File handling allows programs to store data permanently in secondary memory (hard disk) instead of temporary RAM storage. This enables data persistence across program executions.

## Key Concepts

### Memory Types
- **RAM**: Temporary storage, data lost when program ends
- **Secondary Memory**: Permanent storage (hard disk), data persists

### File Stream Classes
- **`ofstream`**: Output file stream for writing data to files
- **`ifstream`**: Input file stream for reading data from files
- **`fstream`**: Bidirectional file stream for both reading and writing

## Code Examples

### 1. Basic File Writing
```cpp
ofstream fout;
fout.open("filename.txt");
if (!fout) {
    cout << "File creation failed!" << endl;
    return 1;
}
fout << "Hello World";
fout.close();
```

### 2. File Reading with getline()
```cpp
ifstream fin;
fin.open("filename.txt");
if (!fin) {
    cout << "File opening failed!" << endl;
    return 1;
}
string line;
while (getline(fin, line)) {
    cout << line << endl;
}
fin.close();
```

### 3. Array Data Processing
```cpp
// Write array data
vector<int> arr = {5, 2, 8, 1, 9};
fout << "Original data: ";
for (int x : arr) {
    fout << x << " ";
}

// Sort and write
sort(arr.begin(), arr.end());
fout << "\nSorted data: ";
for (int x : arr) {
    fout << x << " ";
}
```

## Important Notes

### File Paths
- **Relative path**: `"filename.txt"` (current directory)
- **Absolute path**: `"C:\\Users\\Name\\folder\\filename.txt"` (full path)

### Reading Methods
- **`fin >> variable`**: Reads until whitespace, skips spaces
- **`fin.get(char)`**: Reads single character including spaces
- **`getline(fin, string)`**: Reads entire line including spaces

### Error Checking
Always check if file operations succeed:
```cpp
if (!fout) {
    // Handle file creation/opening failure
}
```

### Best Practices
1. Always close files after operations: `file.close()`
2. Check file operations for success
3. Use absolute paths if relative paths fail
4. Handle file operation errors gracefully

## Real-World Application
The example demonstrates a practical scenario where data is processed (sorting) and stored permanently, simulating file exchange between users in different locations.