$(document).ready(function() {
    var app = new Vue({
        el: '#app',
        data: {
            users: []
        },
        methods: {
            fetchUsers() {
                $.ajax({
                    url: '/users',
                    method: 'GET',
                    success: function(data) {
                        this.users = data;
                    }.bind(this)
                });
            },
            deleteUser(id) {
                $.ajax({
                    url: '/users/' + id,
                    method: 'DELETE',
                    success: function() {
                        this.fetchUsers();
                    }.bind(this)
                });
            }
        },
        mounted() {
            this.fetchUsers();
        }
    });
});
