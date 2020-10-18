from django.contrib import admin
from groups.models import Group, GroupMember


class GroupMemberInLine(admin.TabularInline):
    model = GroupMember

admin.site.register(Group)