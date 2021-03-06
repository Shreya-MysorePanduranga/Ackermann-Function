Vivado HLS 2019.1

Step 1 : Create a new project
Create a new project in Vivado HLS targeting Zybo xc7z010clg400-1 (Zybo board).
1-2 : Launch Vivado HLS. Select Start > All Programs > Xilinx Design Tools > Vivado 2019.1 >Vivado HLS > Vivado HLS 2019.1
1-3 : In the Getting Started GUI, click on Create New Project. The New Vivado HLS Project wizard opens.
1-4 : Click the Browse… button of the Location field and browse to desired location to create the project and then click OK.
1-5 : Give desired name for Project Name.
1-6 : Click Next.
1-7 : In the Add/Remove Files window, type Ack as the Top Function name. (Note: Keep this name in sync with the Ack function in the code)
1-8 : Click Next twice, bypassing to Add any files at the moment.
1-9 : Use "..." button to browse and select "Zybo" Board from the Boards Tab. (Part Number: xc7z010clg400-1)
1-10 : Click Finish to create the New Project.
1-11 : Right click and Add New files to "Source" and "Test Bench" folders in .cpp format. Let's call them 'Ack.cpp' and 'Ack_test.cpp' respectively.
1-12 : Open both files and write the C++ Ack logic code and testbench in the Ack.cpp and Ack_test.cpp files respectively.

Step 2 : Run C Simulation 
Run C simulation to view the expected output.
2-1 : Right click on Project -> Run C Simulation or click on it from the tools bar buttons.
2-2 : Select "Launch Debugger", "Build Only", and "Clean Build"and Click OK in the C Simulation Dialog window.
2-3 : The files will be compiled and you will see the output in the Console window.
2-4 : After the Simulation is successful, Debugger Window is launched automatically.
2-5 : Click on "Resume" button (||> symbol) on the top left to see the output from the testbench.
2-6 : The Console shows the output if the code ran successfully.

Step 2.A : In case of unexpected output, Run Debugger to find out the statement causing the issue
2.A-1 : Run the application in debugger mode and understand the behavior of the program. 
2.A-2 : Select Project > Run C Simulation or click on from the tools bar buttons. Select the Launch Debugger option and click OK.
2.A-3 : The Debug perspective will show the Ack_test.cpp in the source view, argc and argv variables defined in the Variables view, Outline view showing the objects which are in the current scope, thread created and the program suspended at the main() function entry point
2.A-4 : Using the Step Over (F6) button several times, observe the execution progress, and observe the variable values updating, as well as computed software result.
2.A-5 : Now click the Resume button or F8 to complete the software computation
2.A-6 : Observe the following computed software result in the variables view. 
2.A-7 : Press the Resume button or Terminate button to finish the debugging session

Step 3 : Synthesize the Design 
3-1 : Switch to the Synthesis view by clicking synthesis on the tools bar
3-2 : Right Click solution1 -> C Synthesis -> Active Solution or click on the button to start the synthesis process.
3-3 : When synthesis is completed, the Synthesis Results will be displayed along with the Outline pane.
3-4 : If you expand solution1 in Explorer, several generated files including report files will become accessible.   
3-5 : The Synthesis Report shows the performance and resource estimates as well as estimated latency in the design.
3-6 : The report also shows the top-level interface signals generated by the tools. 

Step 4 : Analyze using Analysis Perspective
4-1 : Switch to the Analysis Perspective and understand the design behavior.
4-2 : Select Solution > Open Analysis Perspective or click on (Analysis) to open the analysis viewer. 
4-3 : Click on ‘+’ of loop Row to expand, and then similarly click on sub-loops Col and Product to fully expand the loop hierarchy. 
4-4 : Expand the Performance Profile hierarchy and note iteration latencies, Trip counts, and overall latencies for each of the nested loops. 
4-5 : Select the Resource Profile tab and observe various resources and where they have been used.
4-6 : In the Performance Matrix tab, select the Resource tab (at the bottom of the page), and expand Expressions, I/O Ports, and Memory Ports entries to view the type of operations, resources used, and in which state they are being used. 

Step 5 : Run C/RTL Co-simulation
Run the C/RTL Co-simulation with the default settings of VHDL. Verify that the simulation passes. 
5-1 : Select Solution -> Run C/RTL Cosimulation or if you are in the synthesis view, click on the toolbar button to open the dialog box so the desired simulations can be selected and run.A C/RTL Co-simulation Dialog box will open
5-2 : Make sure to select "Vivado Simulator" under 'Verilog/VHDL Simulator Selection' and "Verilog" for 'RTL Selection'. Keep 'dump trace' to "all" and select "Optimizing Compile", "Reduce Diskspace", and "Wave Debug".
5-3 : Click OK to run the simulation. 
5-4 : Once the simulation verification is completed, the simulation report tab will open showing the results. The report indicates if the simulation passed or failed.
5-5 : A temporary Vivado project would open to show the Wave Outputs.

Step 6 Export RTL 
6-1 : Select Solution -> Export RTL

Vivado 2019.1

Step 1 : Add IP Repository
1-1 : Click on IP catalog to add the exported Ack IP to the repository exported from Vivado HLS.
1-2 : In IP catalog tab,right click and select add repository and choose the path where the Ack IP was exported to.

Step 2 : Creation of Block Deisgn through IP Integrator
2-1 : Click on Create Block Design
2-2 : Press the '+' icon to add the IP's(Ack, Zynq7, Axi Interconnect, Axi Direct Memory Access, Concat)
2-3 : Click on "Run Connection Automation" and select all the IPs on the canvas and click OK.
2-4 : For this Design, customise the ZYNQ IP by double clicking on it:
2-4.a : Select "S AXI HP0 interface" from PS-PL Configuration.
2-4.b : Select "Modem Signals" under "UART 1" under "I/O Peripherals" in the MIO Configuration
2-4.c : Select "IRQ_F2P[15:0]" along with and under "Fabric Interrupts" in Interrupts.
2-5 : Click on "Run Connection Automation" again.
2-6 : Customise the AXI Interconnect connected to the "S_AXI_HP0" pin of the ZYNQ Processor. Change the number of Slaves to 2 and Masters to 1. (Let us call this AXI Interconnect 2 and the other AXI Interconnect 1)
2-7 : Customise the Concat Block to have 3 Ports.
2-8 : Customise the AXI Direct Memory Access Block to disable "Scatter Gather Engine".
2-9 : Click on "Run Block Automation" to let Vivado tool make all important connections for the design to function.
2-10 : Make the following connections:
2-10.a : Connect the "inStream" pin of the Ack block to "M_AXIS_MM2S" pin of AXI DMA and "outStream" pin to "M_AXIS_S2MM" pin of the same.
2-10.b : Connect the "interrupt" pin of the Ack block with the "In2" port of the Concat block
2-10.c : Connect the "mm2s_introut" and "s2mm_introut" pins of AXI DMA to the "In0" and "In1" ports of the Concat block respectively.
2-10.d : Connect the "doubt[2:0]" pin of the Concat block with the "IRQ_F2P[2:0]" pin of the ZYNQ Processor.
2-11 : Click on "Validate Design" to connect any
2-12 : Check for Warnings/Errors and rectify them.
2-13 : Go to Sources Tab, drop down to "Design Sources", right click on your block, select "Create HDL Wrapper".

Step 3 : Run Synthesis
3-1 : Click on "Run Synthesis"
3-2 : Post successfull synthesis, you can read reports like Timing Summary, Methodology, DRC, Noise, Utilization, Power, and also the Schematic.
3-3 : You can also use the Constraints Wizard to add constraints to your design.

Step 4 : Run Implementation
4-1 : Click on "Run Implementation"
4-2 : Post successfull implementation, you can read reports like Timing Summary, Methodology, DRC, Noise, Utilization, Power, and also the Schematic.
4-3 : You can also use the Constraints Wizard to add constraints to your design.

Step 5 : Generate Bitstream and Launch SDK
5-1 : Click on "Generate Bitstream"
5-2 : Select "Export Hardware" in the File -> Export menu, select "include bitstream" in the pop-up window.
5-3 : Select "Launch SDK" in the File menu.

Software Development Kit (SDK)

Step 1: Once SDK is launched, a filename "{block_design_name}_wrapper_hw_platform_0" will be found on the left panel.
2 : Click File -> New -> Application Project
3 : Give project name and check whether "{block_design_name}_wrapper_hw_platform_0" is selected by default for Hardware Platform, Click Next.
4 : Select helloworld template and click on Finish
5 : Open the "helloworld.c" file from the project folder(Project explorer) dropdown -> src -> helloworld.c
6 : Write the C code for Ack.
7 : Build the project.
8 : Connect the Zybo board to the PC.
9 : Click on 'Program FPGA' and click OK.
10 : Add the COM port to which FPGA is connected in the SDK terminal by clicking on '+' icon.(If more than one COMs are connected to the system, COM used for FPGA can be checked from Device Manager)
11 : Right click on project folder and select as Run As -> Launch on Hardware (System Debugger)
12 : Ack output will be displayed in the SDK terminal.


    

 