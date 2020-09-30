from rest_framework import serializers

from .models import Post


class PostListSerializer(serializers.ModelSerializer):
    class Meta:
        model = Post
        fields = [
            'user',
            'title',
            'slug',
        ]


class PostDetailSerializer(serializers.ModelSerializer):
    class Meta:
        model = Post
        fields = [
            'user',
            'title',
            'slug',
            'content'
        ]


class PostUpdateSerializer(serializers.ModelSerializer):
    class Meta:
        model = Post
        fields = [
            'user',
            'title',
            'content'
        ]


class PostCreateSerializer(serializers.ModelSerializer):
    class Meta:
        model = Post
        fields = [
            'title',
            'content',
            'slug',
            'image',
            'draft',
            'publish',
            'read_time'
        ]
