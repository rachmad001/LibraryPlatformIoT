module.exports = class Platform {
    constructor(server, port, token) {
        this.server = server;
        this.token = token;
        this.port = port;
        this.http = require('http');
        this.createProjectResponse = "";
        this.getListProjectResponse = "";
        this.editProjectResponse = "";
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
}
