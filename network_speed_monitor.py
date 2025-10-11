"""
Network Speed Monitor
Author: <your-name>
Description:
    A simple Python program to measure your internet upload and download speed
    using the 'speedtest' module. Displays results neatly in Mbps.
"""

import speedtest

def test_speed():
    print("Testing your internet speed... Please wait.\n")

    # Create a Speedtest object
    st = speedtest.Speedtest()
    st.get_best_server()

    download_speed = st.download() / 1_000_000  # Convert from bits/s to Mbps
    upload_speed = st.upload() / 1_000_000

    print(f"Download Speed: {download_speed:.2f} Mbps")
    print(f"Upload Speed  : {upload_speed:.2f} Mbps")

if __name__ == "__main__":
    try:
        test_speed()
    except Exception as e:
        print("Error occurred while testing speed:", e)
        print("Tip: Make sure you have internet access and 'speedtest-cli' installed.")
