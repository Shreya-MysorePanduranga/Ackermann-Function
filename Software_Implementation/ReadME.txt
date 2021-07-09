Software Development Kit (SDK)

Step 1: Go to start menu and search for SDK.
2 : Once SDK is opened, browse the path for hardware implemented design where SDK design was created for Ack and click on OK.
3 : click File -> New -> Application Project and give project name and click on OK.
4 : select helloworld template and click on Finish.
5 : Open the "helloworld.c" file from the project folder(Project explorer) dropdown -> src -> helloworld.c
6 : Write the C code for Ack.
7 : Build the project.
8 : Connect the Zybo board to the PC.
9 : Click on 'Program FPGA' and click OK.
10 : Add the COM port to which FPGA is connected in the SDK terminal by clicking on '+' icon.(If more than one COMs are connected to the system, COM used for FPGA can be checked from Device Manager)
11 : Right click on project folder and select as Run As -> Launch on Hardware (System Debugger)
12 : Ack output will be displayed in the SDK terminal.