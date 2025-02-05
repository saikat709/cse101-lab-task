# import os
# import time
# import shutil
# from datetime import datetime

# offset = 1;

# def display_file_times(filepath):
#     creation_time = os.path.getctime(filepath)
#     modification_time = os.path.getmtime(filepath)

#     print("Before Modification:")
#     print(f"Creation Time: {datetime.fromtimestamp(creation_time)}")
#     print(f"Modification Time: {datetime.fromtimestamp(modification_time)}")

# def modify_file_times(filepath, new_creation_time, new_modification_time):
#     os.utime(filepath, (new_creation_time, new_modification_time))
#     if os.name == 'nt':
#         import pywintypes
#         import win32file
#         import win32con

#         handle = win32file.CreateFile(
#             filepath,
#             win32file.GENERIC_WRITE,
#             0,
#             None,
#             win32con.OPEN_EXISTING,
#             0,
#             None
#         )
#         win32file.SetFileTime(
#             handle,
#             pywintypes.Time(new_creation_time),
#             pywintypes.Time(new_creation_time),
#             pywintypes.Time(new_modification_time)
#         )
#         handle.close()

#     temp_new_file = filepath + ".tmp"
#     shutil.copy2(filepath, temp_new_file)
#     os.utime(temp_new_file, (new_creation_time, new_modification_time))
#     os.remove(filepath)
#     os.rename(temp_new_file, filepath)


# def handle_modify(file_path):
#     display_file_times(file_path)
#     new_creation_time     = time.mktime(datetime(2025, 1, 21, 11, 0, 0).timetuple())
#     new_modification_time = time.mktime(datetime(2025, 1, 21, 10, 0, 0).timetuple())

#     modify_file_times(file_path, new_creation_time, new_modification_time)

#     print("\nAfter Modification:")
#     display_file_times(file_path)


# def main():
#     folder = "./chapter_6/"
#     for root, _, files in os.walk(folder):
#         for file in files:
#             filepath = os.path.join(root, file)
#             print(f"Processing file: {filepath}")
#             handle_modify(filepath)


# if __name__ == "__main__":
#     main()



# import os
# from datetime import datetime

# def change_folder_timestamps(folder_path, new_access_time, new_modification_time):
#     os.utime(folder_path, (new_access_time, new_modification_time))
#     print(f"Timestamps updated for folder: {folder_path}")

# if __name__ == "__main__":
#     folder_path = "./chapter_5/Mastery"
#     new_access_time       = datetime(2025, 1, 21, 12, 0, 0).timestamp()
#     new_modification_time = datetime(2025, 1, 21, 12, 0, 0).timestamp()

#     change_folder_timestamps(folder_path, new_access_time, new_modification_time)


# import os

# def main():
#     folder = "./"
#     for root, _, files in os.walk(folder):
#         for file in files:
#             filepath = os.path.join(root, file)
#             print(f"Processing file: {filepath}")
#             newname = filepath.split('/')
#             newname[-1] = newname[-1].replace(',', '.')
#             newname = '/'.join(newname)
#             os.rename( filepath, newname)
#             print(f"Processed  file: {newname}")


# if __name__ == "__main__":
#     main()
