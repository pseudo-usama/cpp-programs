const express = require('express')
const router = express.Router()
const { authUser } = require('../basic-auth')
const { canViewProject, scopedProjects, canDeleteProject } = require('../permissions/project')
const { projects } = require('../data')

// All Projects
router.get('/', authUser, (req, res) => {
    res.json(scopedProjects(req.user, projects))
})

// Specific Project
router.get('/:projectId', setProject, authUser, authGetProject, (req, res) => {
    res.json(req.project)
})

// Delete Project
router.delete('/:projectId', setProject, authUser, authDeleteProject, (req, res) => {
    res.send('Deleted project')
})

// Find the project
function setProject(req, res, next) {
    const projectId = parseInt(req.params.projectId)
    req.project = projects.find(project => project.id === projectId)

    if (req.project == null) {
        res.status(404).send('Project not found')
    }
    next()
}

// Authenticate if user has access to view certain project
function authGetProject(req, res, next) {
    if (!canViewProject(req.user, req.project)) {
        return res.status(401).send('Not Allowed')
    }
    next()
}

// Authenticate if user has access to delete certain project
function authDeleteProject(req, res, next) {
    if (!canDeleteProject(req.user, req.project)) {
        return res.status(401).send('Not Allowed')
    }
    next()
}

module.exports = router
