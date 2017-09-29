# Beer Sheets Analytic Tool
A cross platform Qt/C++ application to read, edit, save, and analyze Fantasy Football BeerSheets
* Read .xlsx, .h5 files storing BeerSheets Fantasy Football data
* Extract metadata and statistical data from the files
* Edit and Save data as .h5 file

## Getting Started

There are several external dependencies needed for this project:
* A working version of Qt; this application was build using Qt 5.9.1
* A working version of the HDF5 library
* A working version of QtXlsxWriter

Links for these can be found below.

### Building the Beer Sheets Analytic Tool

* For all users, the HDF5 path must be set in the beer_sheets_tool.pri file

* Put the source code in any directory you like

* Go to top directory of the project in a terminal and run

```
    qmake
    make
```

* The application can then be found in bin
