#!/bin/bash
echo "Top 10 Process in Desending Order :"
ps aux --sort=-pid | head -10
