#pragma once

#include <string>
#include <cstdint>
#include <unordered_map>
#include <stdexcept>
#include <type_traits>
#include <format>


namespace sfe
{
	template <typename Resource, typename Identifier>
	class ResourceContainer
	{
	private:
		struct TrackedResource
		{
			std::unique_ptr<Resource> resource;
			size_t used = 0;
		};
		std::unordered_map<Identifier, TrackedResource> mResourceMap;
	public:
		void load(const Identifier& id, const std::string& filepath)
		{
			auto resource = std::make_unique<Resource>();
			// TODO: TMP string and enum types
			if constexpr (std::is_same_v<Identifier, std::string>)
			{
				if (!resource->loadFromFile(filepath)) throw std::runtime_error(std::format("Failed to load resource '{}' from '{}'", id, filepath));
				auto inserted = mResourceMap.insert(std::make_pair(id, TrackedResource{ .resource = std::move(resource) }));
				if (!inserted.second) throw std::runtime_error(std::format("Failed to insert resource '{}'", id));
			}
			else
			{
				if (!resource->loadFromFile(filepath)) throw std::runtime_error(std::format("Failed to load resource '{}' from '{}'", static_cast<uint32_t>(id), filepath));
				auto inserted = mResourceMap.insert(std::make_pair(id, TrackedResource{ .resource = std::move(resource) }));
				if (!inserted.second) throw std::runtime_error(std::format("Failed to insert resource '{}'", static_cast<uint32_t>(id)));
			}
		}

		template<typename ...Params>
		void load(const Identifier& id, const std::string& filepath, Params... params)
		{
			auto resource = std::make_unique<Resource>();
			// TODO: TMP string and enum types
			if constexpr (std::is_same_v<Identifier, std::string>)
			{
				if (!resource->loadFromFile(filepath, std::forward(params)...)) throw std::runtime_error(std::format("Failed to load resource '{}' from '{}'", id, filepath));
				auto inserted = mResourceMap.insert(std::make_pair(id, TrackedResource{ .resource = std::move(resource) }));
				if (!inserted.second) throw std::runtime_error(std::format("Failed to insert resource '{}'", id));
			}
			else
			{
				if (!resource->loadFromFile(filepath, std::forward(params)...)) throw std::runtime_error(std::format("Failed to load resource '{}' from '{}'", static_cast<uint32_t>(id), filepath));
				auto inserted = mResourceMap.insert(std::make_pair(id, TrackedResource{ .resource = std::move(resource) }));
				if (!inserted.second) throw std::runtime_error(std::format("Failed to insert resource '{}'", static_cast<uint32_t>(id)));
			}

		}

		Resource& require(const Identifier& id)
		{
			if constexpr (std::is_same_v<Identifier, std::string>)
			{
				if (!mResourceMap.contains(id)) throw std::runtime_error(std::format("Failed to acquire resource '{}'", id));
			}
			else
			{
				if (!mResourceMap.contains(id)) throw std::runtime_error(std::format("Failed to acquire resource '{}'", static_cast<uint32_t>(id)));
			}

			auto& trackedResource = mResourceMap.at(id);
			++trackedResource.used;

			return *trackedResource.resource;
		}

		//const Resource& require(const Identifier& id) const
		//{
		//	if (!mResourceMap.contains(id)) throw std::runtime_error(std::format("Failed to acquire resource '{}'", id));
		//	auto& trackedResource = mResourceMap.at(id);
		//	++trackedResource.used;

		//	return *trackedResource.resource;
		//}

		void release(const Identifier& id)
		{
			if constexpr (std::is_same_v<Identifier, std::string>)
			{
				if (!mResourceMap.contains(id)) throw std::runtime_error(std::format("Failed to release resource '{}'", id));
			}
			else
			{
				if (!mResourceMap.contains(id)) throw std::runtime_error(std::format("Failed to release resource '{}'", static_cast<uint32_t>(id)));
			}

			auto& trackedResource = mResourceMap.at(id);
			--trackedResource.used;

			if (trackedResource.used == 0) mResourceMap.erase(mResourceMap.find(id));
		}

		size_t size() const { return mResourceMap.size(); }
	};
}

