// Check only if User is logged in
function authUser(req, res, next) {
    if (req.user == null) {
        return res.status(403).send('You need to sign in.')
    }
    next()
}

// Check if is Admin or Basic user
function authRole(role) {
    return (req, res, next) => {
        if (req.user.role !== role) {
            return res.status(401).send('Not allowed')
        }
        next()
    }
}

module.exports = {
    authUser,
    authRole
}
