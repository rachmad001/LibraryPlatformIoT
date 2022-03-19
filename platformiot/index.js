module.exports = class Platform {
    constructor(server, port, token) {
        this.server = server;
        this.token = token;
        this.port = port;
        this.http = require('http');
        this.createProjectResponse = "";
        this.getListProjectResponse = "";
        this.editProjectResponse = "";
        this.deleteProjectResponse = "";
        this.createDeviceResponse = "";
        this.getListDeviceResponse = "";
        this.editDeviceResponse = "";
        this.deleteDeviceResponse = "";
        this.addDataResponse = "";
        this.getDataResponse = "";
    }
    createProject(nameProject, description) {
        this.createProjectResponse = "";
        var data = JSON.stringify({
            token: this.token,
            nameproject: nameProject,
            description: description
        })

        const options = {
            hostname : this.server,
            port: this.port,
            path: '/create/project',
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            }
        }
        const req = this.http.request(options, res => {
            res.on('data', d => {
                this.createProjectResponse = d.toString();
                // console.log(d.toString())
            });
        })
        req.write(data);
        req.on('error', error => {
            console.error(error);
            this.createProjectResponse = 'error : '+error.message;
          })
        req.end();
    }
    getListProject() {
        this.getListProjectResponse = "";
        const options = {
            hostname: this.server,
            port: this.port,
            path: '/listProject',
            method: 'GET',
            headers: {
                'token': this.token
            }
        }
        const req = this.http.request(options, res => {
            res.on('data', d => {
                this.getListProjectResponse = d.toString();
            })
        })
        req.on('error', error => {
            this.getListProjectResponse = 'error : '+error.message;
        })
        req.end()
    }
    editProject(oldName, newName, description){
        this.editProjectResponse = "";
        const data = JSON.stringify({
            token: this.token,
            oldname: oldName,
            newname: newName,
            description: description
        })
        const options = {
            hostname: this.server,
            port: this.port,
            path: '/edit/project',
            method: 'PUT',
            headers: {
                'Content-Type': 'application/json'
            }
        }
        const req = this.http.request(options, res => {
            res.on('data', d => {
                this.editProjectResponse = d.toString();
            })
        })
        req.write(data);
        req.on('error', error => {
            this.editProjectResponse = 'error : '+ error.message;
        })
        req.end()
    }
    deleteProject(nameProject){
        this.deleteProjectResponse = "";
        const options = {
            hostname: this.server,
            port: this.port,
            path: '/delete/'+nameProject,
            method: 'DELETE',
            headers: {
                'token': this.token
            }
        }
        const req = this.http.request(options, res => {
            res.on('data', d => {
                this.deleteProjectResponse = d.toString();
            })
        })
        req.on('error', error => {
            this.deleteProjectResponse = 'error : '+error.message
        })
        req.end()
    }
    createDevice(nameProject, nameDevices){
        this.createDeviceResponse = "";
        const data = JSON.stringify({
            token: this.token,
            project: nameProject,
            devices: nameDevices
        })
        const options = {
            hostname: this.server,
            port: this.port,
            path: '/create/devices',
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            }
        }
        const req = this.http.request(options, res => {
            res.on('data', d => {
                this.createDeviceResponse = d.toString();
            })
        })
        req.write(data);
        req.on('error', error => {
            this.createDeviceResponse = "error : "+error.message;
        })
        req.end();
    }
    getListDevice(nameProject){
        this.getListDeviceResponse = "";
        const options = {
            hostname: this.server,
            port: this.port,
            path: '/listDevices/'+nameProject,
            method: 'GET',
            headers: {
                'token': this.token
            }
        }
        const req = this.http.request(options, res => {
            res.on('data', d => {
                this.getListDeviceResponse = d.toString();
            })
        })
        req.on('error', error => {
            this.getListDeviceResponse = 'error : '+error.message;
        })
        req.end()
    }
    editDevice(nameProject, oldNameDevice, newNameDevie){
        this.editDeviceResponse = "";
        const data = JSON.stringify({
            project: nameProject,
            oldname: oldNameDevice,
            newname: newNameDevie
        })
        const options = {
            hostname: this.server,
            port: this.port,
            path: '/edit/devices',
            method: 'PUT',
            headers: {
                'Content-Type': 'application/json',
                'token': this.token
            }
        }
        const req = this.http.request(options, res => {
            res.on('data', d => {
                this.editDeviceResponse = d.toString();
            })
        })
        req.write(data);
        req.on('error', error => {
            this.editDeviceResponse = 'error : '+error.message;
        })
        req.end()
    }
    deleteDevice(nameProject, nameDevice){
        this.deleteDeviceResponse = "";
        const options = {
            hostname: this.server,
            port: this.port,
            path: '/delete/'+nameProject+'/'+nameDevice,
            method: 'DELETE',
            headers: {
                'token': this.token
            }
        }
        const req = this.http.request(options, res => {
            res.on('data', d => {
                this.deleteDeviceResponse = d.toString();
            })
        })
        req.on('error', error => {
            this.deleteDeviceResponse = 'error : '+error.message;
        })
        req.end()
    }
    addData(nameProject, nameDevice, dataDevices){
        this.addDataResponse = "";
        const data = JSON.stringify({
            token: this.token,
            nameproject: nameProject,
            data: dataDevices,
            namedevices: nameDevice
        })
        const options = {
            hostname: this.server,
            port: this.port,
            path: '/addData',
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            }
        }
        const req = this.http.request(options, res => {
            res.on('data', d => {
                this.addDataResponse = d.toString();
            })
        })
        req.write(data);
        req.on('error', error => {
            this.addDataResponse = 'error : '+error.message;
        })
        req.end()
    }
    getData(nameProject, nameDevice){
        this.getDataResponse = "";
        const options = {
            hostname: this.server,
            port: this.port,
            path: '/data/'+nameProject+'/'+nameDevice,
            method: 'GET',
            headers: {
                'token': this.token
            }
        }
        const req = this.http.request(options, res => {
            res.on('data', d => {
                this.getDataResponse = d.toString();
            })
        })
        req.on('error', error => {
            this.getDataResponse = 'error : '+error.message;
        })
        req.end()
    }
}
