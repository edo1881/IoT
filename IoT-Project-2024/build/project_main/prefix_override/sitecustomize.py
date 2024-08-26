import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/zephyrus/Desktop/IoT/IoT-Project-2024/install/project_main'
