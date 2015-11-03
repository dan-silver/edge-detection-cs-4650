//Compiling CImg Assignment - I - Part A
//Author - Rengarajan - last edited - Aug 31st 2014
//Purpose - Comprehensive walkthrough showing steps of how to setup CImg and compile Sample CImg code
//Target audience - Beginner/Intermediate, The advanced users can skim through the list and find out about the requirements


Required software : 7-Zip - Download and install x64 or x86 version - Free and open source software that opens .zip, .7z, .tar,.tar.gz and many more


For Windows users:
This guide will show you how to setup your Windows x86/64 environment to compile and work with the Assignment -I with CImg

1: Get Visual Studio professional/ultimate 2010/12/13 from Mizzou : http://engineering.missouri.edu/cs/degree-programs/  ('Why not Express?' will be an article by itself at a later point in time)
Scroll down to Software Downloads and click on Microsoft MSDNAA software. 
Enter your pawprint and password and click on 'Developer Tools' on the left hand side panel. 
Download using Dreamspark and follow the on screen instructions. Install VS on default paths.
Note : VS 2010 does not fully support C++11 and while in this class we are not going to use C++11 instructions this is something you have to note for the future, however, VS-2010 is amongst the most tried and tested IDEs to get this job done.


2: Download CMake from Kitware's website here : http://www.cmake.org/cmake/resources/software.html
This is a binary and there is no need to compile from source. Grab the setup file and install as you would normally using default paths and settings.
Note : One does not need the knowledge of the (CMake) scripting language in order to use it (That's why you have TAs!) and the files necessary to make a successful build have been provided in the archive. Learning CMake is highly recommended though not required for this class.
Some CMake tutorials : http://www.cmake.org/cmake/help/cmake_tutorial.html - REMEMBER!!! - THIS IS NOT A REQUIRED READ but I personally, highly encourage you to read up on CMake AFTER you complete the compilation of this project and finish Assignment - I if you aren't already familiar with it.


3: Download the code archive from Blackboard under course content. Un(tar/zip/rar) this archive and make a new folder and name it appropriately because this is where all your projects for this class will reside (Being organized is important as it helps in the long run while using libraries and doing multi-library compiles)


4: Run cmake-gui from the CMake install folder (under '/{cmake install root}/bin'). Under 'Where is the source code:' enter the path to the above extracted path (for e.g. C:/Users/my_username/Assignment-1-part A/) and under 'where to build the binaries' : enter the same path as above and concatenate something like '{prev_folder_path/bin}' (for e.g. C:/Users/my_username/Assignment-1-part A/bin)
Note: Please make note of the file separator. CMake follows the *nix way of slashes to separate directories. Please follow the same in order maintain the standard way even though Windows file separators will work just fine.


5: Click on 'Configure' (from the dropdown box select Visual Studio - 2010 (or any other flavor that you have running on your current machine)) and there will be errors configuring but this is normal! Scroll the output panel below and there are two required libraries namely libpng and libjpeg. These are needed (strictly required) as we will be reading *.jpg and *.png files for our assignment.
You may have noticed that there are optional libraries that may or may not be missing but these are not any cause for concern for this assignment.

//People who know or have already build libpng, libjpeg & zlib should skip the next step.

6: Now, we need to compile these image format libraries so that we are able to read in the images. Understanding dependencies is important to a simple build process which will also save you a lot of time. 
libpng depends on zlib and one will need to compile zlib first. I have uploaded the source files and everything that you would possibly need right here :
a) zlib - http://meru.cs.missouri.edu/~rvpnc4/libs/zlib-1.2.8/zlib-128-src.tar
b) libpng - http://meru.cs.missouri.edu/~rvpnc4/libs/libpng-1.6.12/png-1612-src.tar
c) libjpeg - http://meru.cs.missouri.edu/~rvpnc4/libs/jpeg-9/jpeg-9-src.tar

Note : You will need CMake installed and running in order to proceed. If you haven't installed CMake yet please see step #2

a) Compiling zlib - Once you have the source untared please make sure to put the files in a meaningful place such as 'C:/zlib/src/'
zlib has a CMakeLists file within the folder that you just untared which means we can generate a VS solution file (Hurray!) using CMake. Run CMake gui and enter the source path (e.g. 'C:/zlib/src/' same as above path). 
You can build the binaries as we did before (e.g. 'C:/zlib/bin')
Click on 'Configure' and select VS 2010 as before and click on 'Generate' (You have just created your very own solution file for your target VS install!). 
Go into this bin folder and open the solution file in your Visual Studio IDE and press 'Build All' or 'Build' (keyboard shortcut is F5)
Now, we have compiled the zlib library. The library is now under 'Debug' or 'Release' folders depending on what your build settings were set to (check under the green build button for a dropdown box which should say 'Release' or 'Debug' and next to it should say 'Win32')
You should have a *.lib file (this is what your library file is) and a *.dll both of which should have the same names! (e.g. zlib.lib & zlib.dll). The dll or dynamic link library is the windows library file that is needed when an executable that was linked using a corresponding .lib file during execution.

b) Compiling libpng - Now that you have compiled zlib we are now ready to compile the png library. Untar as usual and remember to put the src files in a meaningful place such as 'C:/png/src/'.
libpng also has a CMakeLists file (oh! what luck!). Follow usual CMake steps and build the binaries in a different folder such as 'C:/png/bin/'.
Click on 'Configure' and this time around you will need to manually set the zlib source and library paths within the CMake GUI as it will throw an error and say zlib not found. Check advanced next to the search field and in the search field type in zlib
Now type in the source path to the same place where you extracted the zlib archive (With all the *.c and *.h files) or in the above example the path would be 'C:/zlib/src'. Now put a semicolon (';') such as 'C:/zlib/src/;C:/zlib/bin' and add in the bin folder too.
In the zlib library path type in the path to zlib.lib along with the filename i.e. in the above example it would be 'C:/zlib/bin/Release/zlib.lib' (this could also be in the debug folder and again depending on what you selected during build time)
Click on generate and it should be successfull. Now, a solution file should have been created such as libpng.sln. Open this in VS and then follow the usual steps to 'Build' or press F5.
Now we have also built the libpng library (rejoice!).

c) Compiling libjpeg - libJPEG does not unfortunately have a CMakeLists but they do have a makefile.vc. This can be made using 'nmake'. nmake is the Visual Studio tool for creating VS solution files from makefiles and it is quite a handy tool.
To use nmake you would need to access Visual Studio Tools and open up the VS Command line (one can either search this under the start menu in Win7 or use the search for Win8 on the right hand side panel after pressing the 'windows' button)
VS cmd line is basically the same cmd line interface with all the paths setup so that we can use nmake. Now, cd into the src folder for libjpeg and type 'nmake -f makefile.vc setup-v10'.
This will generate a jpeg.sln. As this is a solution file you may proceed as usual and open this up in VS and build.


7: Run CMake again on our assignment folder as in step #5 and press 'Configure'. This will throw the same errors as before with missing libraries. 
Check 'Advanced' next to the search bar in CMake-GUI and now type in zlib. 
Enter the zlib source and library files as we did before building libpng.
Click on 'Configure' again.
Enter 'png' in the search bar and this time enter the PNG_PNG_RELEASE_LIB -> point this to the 'Release' libpng.lib which should be where we built it in the last step for e.g. under 'C:/png/bin/Release/libpng.lib'
Enter the PNG_PNG_SOURCE -> point this to the *.c and *.h files under for e.g. 'C:/png/' and also under 'C:/png/bin/' which should look like 'C:/png/;C:/png/bin/;C:/png/bin/Release' separated by ';' as shown
Click on 'Configure' again. Now, you should see only one missing library which is libjpeg.
Type jpeg or jpg and manually enter the path to jpg source which should be something lie 'C:/jpg/' and the library should be 'C:/jpg/libjpeg.lib'.
Click on 'Configure' again and this time you should not see any errors and now click on 'Generate'! Congratulations! You are now ready to compile the sample code and begin your image processing coding!
Open the solution file in VS and Build as usual. This should generate an executable. 


8: Runtime setup:
Now that we have an executable the next step is to run it, however, remember that you have linked to *.lib files such as zlib.lib, libpng.lib & libjpeg.lib. A lib file as stated above is used for linking but there needs to be a corresponding dll file in the search path so that the executable can run.
We can set this up WITHOUT copying all the dlls in the same folder as 'introdemo.exe'. The proper way to do this is to setup the windows environment variable called 'PATH' (yes, all in caps!). In Win7 right click on 'My Computer' -> Properties ->  Advanced system settings
Now, click on the 'Advanced' tab and click on 'Environment Variables'. If you do not see 'PATH' already then create one and name is PATH and in the box below type the paths to the the 3 dlls (zlib,png & jpg),
for e.g. 'C:/zlib/bin/Release/;C:/png/bin/Release/;C:/jpeg/bin/Release/' (remember to check if the dlls exist in these paths and DO NOT forget to put a semicolon separating the 3 paths!
Now you will need to close all open terminals or cmd prompts and start a fresh one and try the command below.

You need to run the executable with the following parameters in a cmd prompt 'introdemo.exe {path_to_some_random_jpeg_or_png_image}'

Note : If there is an error such as '*.dll not found..reinstalling the program might help' then you haven't setup step #8 properly. Go back and slowly read all the details and try again.

Remember that you have set this up ONLY ONCE and this should help for all future assignments!  


Linux users:

Most of this should be familiar to you and you will however, NOT be required to build libpng,zlib and libjpeg by yourself. Most distros of linux come with their own prebuilt libraries and I highly recommend that you simply install them.
I will list the most common repositories but there may be others and of course most distros are only flavors or forks and hence should work for most.

For Debian (Ubuntu, eOS etc):
sudo apt-get update
sudo apt-get install libpng-dev,libjpeg-dev,zlibc

For RHEL (Red Hat, CentOS etc):
yum install libpng-dev,libjpeg-dev,zlibc (google to check the names of these..they do change a lot....)

Note: There is also no reason not to build from source. For all the above source files for png, jpeg and zlib I have included a MakeFile or a CMakefile and the CMake procedure would be the same as in Windows but for libjpeg just do a './configure' and 'make install'.


Mac users:
One known X11 issue but other than that the same as Linux. Run CMake and see what errors you get in your XCode project. Hopefully the X11 issue has been solved else we can discuss this further and solve it.












