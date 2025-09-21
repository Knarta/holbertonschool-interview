# 📊 Log Parsing

## 🎯 Description
Python script that reads logs in real-time from standard input and computes statistics on HTTP requests.

## 📚 **Simplified Project Explanation**

### 🔄 **How Does It Work?**

#### **1. The Generator (`0-generator.py`)**
```
💻 Simulates a web server that generates logs
📝 Each line = one HTTP request
⏰ Generates 10,000 lines with random delays
```

#### **2. The Analyzer (`0-stats.py`)**
```
👀 Reads each line from the generator
🔍 Checks if the format is correct
📊 Counts statistics
📈 Displays summary every 10 lines
```

### **The Generator Produces:**
- 🌐 **Random IP**: `192.168.1.1`
- 📅 **Date/time**: `[2023-01-01 12:00:00]`
- 🔗 **Fixed request**: `"GET /projects/260 HTTP/1.1"`
- 🎲 **Random code**: `200` (success), `404` (error), etc.
- 📦 **Random size**: `1024` bytes

### **The Analyzer Calculates:**
- 📏 **Total size**: Sum of all files
- 🔢 **Error counters**: How many 200, 404, 500, etc.

## 📁 Files
- `0-stats.py` - Main log analysis script
- `0-generator.py` - Test log generator

## 🚀 Usage

### Basic execution
```bash
./0-generator.py | ./0-stats.py
```

### **What Happens:**
1. 🏗️ The generator creates logs
2. 📡 Logs pass to the analyzer via a "pipe" (`|`)
3. 📊 The analyzer displays stats every 10 lines
4. ⏹️ CTRL+C to stop and see final result

### Test with custom data
```bash
echo '192.168.1.1 - [2023-01-01 12:00:00] "GET /projects/260 HTTP/1.1" 200 1024' | python3 0-stats.py
```

## 📝 Log format
```
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
```

**Example:**
```
192.168.1.1 - [2023-01-01 12:00:00] "GET /projects/260 HTTP/1.1" 200 1024
```

## 📈 Statistics displayed

### When?
- ✅ Every 10 valid lines
- ✅ On keyboard interruption (CTRL+C)

### What?
- **Total size:** `File size: <total>`
- **Status codes:** Number of occurrences per code
  - Supported codes: 200, 301, 400, 401, 403, 404, 405, 500
  - Sorted in ascending order
  - Only codes with occurrences are displayed

## 💡 Output example

### **After 10 lines:**
```
File size: 5213
200: 2    ← 2 successful requests
404: 3    ← 3 pages not found
500: 1    ← 1 server error
```

### **Meaning:**
- 📦 **5213 bytes** transferred in total
- ✅ **2 successes** (code 200)
- ❌ **3 404 errors** (page not found)
- 🚨 **1 500 error** (server problem)

## 🛡️ **Error Handling**

### **Ignored Lines:**
```
❌ "badly formatted line"         → ignored
❌ "192.168.1.1 GET 200 1024"    → incorrect format
✅ "192.168.1.1 - [date] ..."    → correct format
```

### **Status Codes:**
- ✅ **Allowed**: 200, 301, 400, 401, 403, 404, 405, 500
- ❌ **Other codes**: counted in size but not displayed

## 💡 **Why Is This Useful?**

### **In Real Life:**
- 🔍 **Monitoring**: Watch a website in real-time
- 📊 **Statistics**: See how many errors per minute
- 🚨 **Alerts**: Detect problems quickly
- 📈 **Performance**: Measure bandwidth usage

### **Skills Learned:**
- 🐍 **Python**: Stream reading, regex, signal handling
- 📝 **Parsing**: Analyze data formats
- 📊 **Statistics**: Count and accumulate data
- 🔄 **Real-time**: Process continuous streams

## ⚠️ Important notes
- Lines with incorrect format are automatically ignored
- The script does not execute when imported
- Use CTRL+C to stop and see final statistics

## 🎯 **Key Points to Remember**

1. 📡 **Data flow**: Generator → Analyzer (via pipe)
2. ⏰ **Real-time**: Line-by-line processing
3. 📊 **Statistics**: Display every 10 lines + CTRL+C
4. 🛡️ **Robustness**: Ignores badly formatted lines
5. 🎮 **Interactive**: Clean stop with CTRL+C

**It's a mini web server monitoring system!** 🚀
