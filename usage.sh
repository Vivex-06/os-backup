#!bin/bash
echo "Display Highest Usage :"
ps aux --sort=%mem | head -10
