import speedtest

def get_speed():
    """Measure download and upload speeds in Mbps and ping in ms."""
    st = speedtest.Speedtest()
    st.get_best_server()
    download = st.download() / 1_000_000  # Convert bps → Mbps
    upload = st.upload() / 1_000_000      # Convert bps → Mbps
    ping = st.results.ping
    return round(download, 2), round(upload, 2), round(ping, 2)
