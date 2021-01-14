# -*- coding: utf-8 -*-

import sys
import socket
import json

class AttoException(Exception):
    def __init__(self, errorText = None, errorNumber = 0):
        self.errorText = errorText
        self.errorNumber = errorNumber


class Device(object):
    TCP_PORT   = 9090
    is_open    = False
    request_id = 0

    def __init__(self, address):
        self.address  = address
        self.language = 0
        self.apiversion = 2

    def __del__(self):
        self.close()

    def connect(self):
        """
            Initializes and connects the selected AMC device.
        """
        if not self.is_open:
            tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            tcp.settimeout(10)
            tcp.connect((self.address, self.TCP_PORT))
            self.tcp = tcp
            if sys.version_info[0] > 2:
                self.bufferedSocket = tcp.makefile("rw", newline='\r\n')
            else:
                self.bufferedSocket = tcp.makefile("rw")
            self.is_open = True

    def close(self):
        """
            Closes the connection to the device.
        Returns
        -------
        """
        if self.is_open:
            self.bufferedSocket.close()
            self.tcp.close()
            self.is_open = False

    def sendRequest(self, method, params=False):
        req = {
                "jsonrpc": "2.0",
                "method": method,
                "id": self.request_id,
                "api": self.apiversion
                }
        if params:
            req["params"] = params
        self.bufferedSocket.write(json.dumps(req))
        self.bufferedSocket.flush()
        self.request_id = self.request_id + 1

    def getResponse(self):
        response = self.bufferedSocket.readline()
        return json.loads(response)

    def request(self,method,params=False):
        """ Synchronous request.
        """
        if not self.is_open:
            raise AttoException("not connected, use connect()");
        self.sendRequest(method, params)
        return self.getResponse()

    def printError(self, errorNumber):
        """ Converts the errorNumber into an error string an prints it to the
        console.
        Parameters
        ----------
        errorNumber : int
        """
        print("Error! " + str(self.system_service.errorNumberToString(self.language, errorNumber)[1]))

    def handleError(self, response, ignoreFunctionError=False):
        if response.get('error', False):
            raise AttoException("JSON error in %s" % response['error'])
        errNo = response['result'][0]
        if (errNo != 0 and errNo != 'null' and not ignoreFunctionError):
            raise AttoException(("Error! " + str(self.system_service.errorNumberToString(self.language ,errNo))), errNo)
        return errNo