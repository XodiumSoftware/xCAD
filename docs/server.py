import json
from http.server import HTTPServer, SimpleHTTPRequestHandler

with open("bbc/constants.py") as f:
    constants_data_json = json.load(f)["constants_data_json"]


class ConstantsHandler(SimpleHTTPRequestHandler):
    def do_GET(self):
        if self.path == "/constantsData":
            self.send_response(200)
            self.send_header("Content-type", "application/json")
            self.end_headers()
            self.wfile.write(constants_data_json.encode())
        else:
            super().do_GET()


server_address = ("", 8000)
httpd = HTTPServer(server_address, ConstantsHandler)
print("Server running on http://localhost:8000/")
httpd.serve_forever()
