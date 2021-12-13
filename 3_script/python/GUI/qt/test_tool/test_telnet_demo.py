from libutils.telnetclient import TelnetClient

tc = TelnetClient()

tc.login_host('192.168.6.19', 'root', '108balance')

tc.e("watch -n 1 | ps")
