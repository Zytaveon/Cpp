# C++ Project Folder - Dakota McMann

---

## Table of Contents
  - // LINKS TO PARTS OF THIS //

---

### What is this?
  - This it my project folder that I am going to try and fill up with a bunch of C++ projects

---

### Why are you doing this?
  - I am going to start applying to jobs here shortly and my Github profile looked horrific in my opinion. I wanted to start from scratch a little bit, which I know will hurt my a little bit, but I think it will be worth it if I keep up the maintainence for my profile
    and keep coding

  - I graduated in December of 2023 with a CS degree and was looking for Software Developer jobs. While applying, I got caught up in Youtube videos seeing what languages are best to get developer jobs. I would code in one language for a week or two and then
    see a different Youtube video and switch to doing a new language. I spent months doing this and by the end I had nothing to show for it as well as not really learning any of the lagnuages that I had been coding in.

  - I eventually got a call for contracted IT work at a hospital and took it. By the time I was hired and working, I wasn't excited to code anymore and so I stopped for the most part, only doing small bits of code here and there.

  - In January 2025 Raylib found me somewhere and it made me want to code. When I first learned code I started in C and saw that Raylib worked in C/C++ so I decided that I am going to get back into coding. I am going to stick to coding in C++ and since Raylib
    is what got me excited, it might be Raylib projects more or less,

  - Starting Janurary 24th, I decided I am going to try and code (or contribute to my coding endeavors such as writing this) at least one hour a day. I know things come up, so if I miss a day here and there I am not going to be too hard on myself, but I want to get back
    to being passionate about building projects. I also decided to only stick to C++ so I am not trying different languages all the time.

  - Before starting this new "adventure" I didn't like github that much, but I know that is a major downfall especially in the software developer community. I am going to try and use Github a lot more, but even as a solo developer I probably won't learn as much
    as I need to, but that is better than nothing. I am also using the Github desktop app for windows so that makes it a bit easier in my opinion.

---

### How do I make these things work?
  - I code on Windows and VSCode so I will give instructions how to do that starting from scratch, but if a step isn't explained well enough or you use a different OS, Youtube is a great tool.

    1. Download VSCode
         - I personally use VSCode, but you can use any text editor you would like (Notepad++, Vim/Nano in the Terminal)
         - If you simply want to see if the project works, this step isn't necessary as well.
         - Here is the link to the VSCode download. Simply click on your OS you have and go through the steps to install. Sorry for not more in depth instructions at the moment.
             - https://code.visualstudio.com/download
          
    2. Download G++
        - This is the compiler for C++. A compiler is to change the human readable code into machine readable code. You will need this to run the code.
          The link below is the exact video I watched to get started and it is on the VSCode page as well so it will work seamlessly for that. The video is only 3 minutes so don't get discouraged.
            - https://youtu.be/oC69vlWofJQ
         
    3. Download Cpp project folder.
        - Download the Cpp project folder and save it somewhere you can remember.
        - I would recommend putting it somewhere in a drive (C:) instead of the Desktop, because it can be harder to navigate to the desktop.
      
    4. Open Terminal and navigate to folder
        - Open the terminal (terminal in VSCode works too).
        - On windows you can naviaget through you fodlers using the "cd <i>NameOfFolder</i>" to go into a folder, "cd .." to get out of the folder, and "ls" to see everything inside a folder.
        - Navigate to the Cpp folder you just downloaded.
      
    5. Go into a project folder and test.
        - I know the GameOfLife project works so I would navigate into that folder.
        - Your terminal line should look something like "...Cpp/GameOfLife" when you are in the correct spot.
        - In every folder there is a run.ps1 file, go ahead and run it by using the command "./run"
        - If you have an error that says something about not being able to run scripts, go ahead and run this command
            - set-executionpolicy remotesigned
        - When you run the ./run command and it works, nothing will show on the terminal, only a new line will appear.
        - Run ./gameoflife and enjoy! A few lines will appear in the terminal, but then a window should pop up on your screen. Use the space bar to iterate through the game of Life
        - You can close the window by using the ESC key or can use the red X in the top right corner.
