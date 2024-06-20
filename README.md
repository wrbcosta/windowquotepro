# windowquotepro
Simple Windows application to create and view quotes for door types

* Extremely simple UI using MFC
* winsqlite3 library used for database implementation

## Functionality
* Create a quote: insert a quote name and the name of the customer, choose the door size/material, and check the price
* Display quotes: view all the quotes created (stored in the back-end DB)

## Design
The application uses [MVC (Model-View-Controller)](https://en.wikipedia.org/wiki/Model%E2%80%93view%E2%80%93controller) design pattern for its components.

![WindowQuotePro_ComponentsDiagram](https://github.com/wrbcosta/windowquotepro/assets/69218767/71576a2c-6557-4de3-a918-c2ff2828abe6)

## Running the code
The code in the repository is ready to be deployed. Simply compile the Visual Studio solution and run the tool's debugger. Or compile the solution and run the portable .exe file anywhere in your system.

The following files will be created in the path of the .exe file:
* AllMyQuotesDB.db - quotes database
* PricerDB.db - prices database
* AllMyQuotes.log - log file
