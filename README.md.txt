# Distributed Appointment Database System

A custom database system for government appointment booking using data structures implemented from scratch in C++.

## Overview

This system manages appointments for NADRA and Passport offices across Pakistan using custom-built data structures instead of traditional database software.

## Data Structures Implemented

- **B-Tree**: Stores appointments sorted by date and time for efficient range queries
- **Hash Table**: Provides O(1) lookup for CNIC and confirmation codes
- **API Layer**: Manages operations between data structures

## Project Structure

DistributedAppointmentDB/
├── src/ # C++ source files
├── include/ # Header files
└── docs/ # Documentation


## Technologies

- **Language:** C++17
- **Platform:** AWS EC2
- **Version Control:** GitHub

## Current Status

Phase 1: Core data structures (B-tree, Hash table)   
Phase 2: API integration - In Progress
