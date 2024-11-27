#!/bin/bash

# Function to clean up the build directory
cleanup() {
  echo "Cleaning up the build directory..."
  cd ..
  rm -rf build
  echo "Script completed."
}

# Trap errors and call the cleanup function
trap cleanup ERR

# Check if the build directory exists
if [ -d "build" ]; then
  echo "The 'build' directory exists, removing it..."
  rm -rf build
fi

# Create a new build directory
echo "Creating the 'build' directory..."
mkdir build
cd build

# Run cmake and make to build the project
echo "Running cmake and make..."
cmake ..
make

# Copy the executable files to the parent directory
echo "Copying the executable files to the parent directory..."
cp runTests ../
cp audio_converter ../

# Go back to the parent directory
cd ..

echo "Script completed."