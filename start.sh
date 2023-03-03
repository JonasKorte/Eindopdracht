#!/bin/bash

echo "Opening Max..."
cd Max
open Eindopdracht.maxpat
cd ..

echo "Checking python dependencies..."

python3 -m pip install keyboard
python3 -m pip install pySerial
python3 -m pip install python-osc

echo "Dependencies installed successfully."

echo "Running Python Script..."
cd Python
sudo python3 bridge.py
cd ..